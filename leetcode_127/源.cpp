class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordL(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int count = 1;
        while (!q.empty())
        {
            //���л����ַ���Ϊ�գ�˵��û��
            if (wordL.empty())
                return 0;
            int sizeQ = q.size();
            while (sizeQ--)
            {
                //һ���ܸı�һ������BFS���Ե�ǰ�ַ��������п��ܣ������ַ����в����Ƿ������ֵ���м�����У��Լ�����ַ���Ӧ��ɾ������ֹ�ظ�ʹ��
                //ʱ�临�Ӷȣ��ַ�������*���ʳ���*26
                string word = q.front();
                for (int i = 0; i < word.size(); i++)
                {
                    string newWord = word;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        newWord[i] = ch;
                        if (wordL.find(newWord) != wordL.end())
                        {
                            //+1�����count��û��++
                            if (newWord == endWord)
                            {
                                return count + 1;
                            }
                            q.push(newWord);
                            //ɾ���Ѿ�ʹ�ù��ģ���ֹ���ʹ��
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