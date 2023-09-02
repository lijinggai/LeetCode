class Solution {
    bool InwordDict(int i, int j, string& s, unordered_set<string>& dictionary)
    {
        string sub = s.substr(i - 1, j - i + 1);
        // cout<<sub<<endl;
        if (dictionary.find(sub) == dictionary.end())
            return false;
        return true;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //子问题：前n个字符是否可以拼接
        //f(i,j)=f(i-1,j)  i<j
        //f(i,j)=f(i-1,j)||(f(i,i-1)&&s.subste(i-1,j-i+1)) i>=j
        int n = s.size();
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());//查找效率高
        vector<bool> res(n + 1, false);
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (i == 1)
                    res[j] = InwordDict(i, j, s, dictionary);
                else
                {
                    // if(i>j)
                    //     res[i][j]=res[i-1][j];
                    // else
                    res[j] = res[j] || (res[i - 1] && InwordDict(i, j, s, dictionary));
                }
            }
        }
        return res[n];
    }
};