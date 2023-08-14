class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordL(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int count = 1;
        while (!q.empty())
        {
            //队列或者字符集为空，说明没有
            if (wordL.empty())
                return 0;
            int sizeQ = q.size();
            while (sizeQ--)
            {
                //一次能改变一个数，BFS尝试当前字符串的所有可能，再在字符集中查找是否有这个值，有加入队列，以加入的字符集应该删除，防止重复使用
                //时间复杂度：字符集个数*单词长度*26
                string word = q.front();
                for (int i = 0; i < word.size(); i++)
                {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        newWord[i] = ch;
                        if (wordL.find(newWord) != wordL.end())
                        {
                            //+1是这次count还没有++
                            if (newWord == endWord)
                            {
                                return count + 1;
                            }
                            q.push(newWord);
                            //删除已经使用过的，防止多次使用
                            wordL.erase(newWord);
                        }
                    }
                }
                q.pop();
            }
            count++;
        }
        return 0;
    }
};