class Solution {
public:
    int minDistance(string word1, string word2) {
        //子问题：word1的一部分变成Word2的一部分的最小操作数
        //f(i,j)=min(f(i,j-1)+1,f(f(i-1,j)+1,f(i-1,j-1)+t))  t=当前字符==匹配字符?0:1
        int m = word1.size();
        int n = word2.size();
        if (m == 0)
            return n;
        if (n == 0)
            return m;
        vector<vector<int>> res(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++)
        {
            res[i][0] = i;
        }
        for (int i = 1; i < n + 1; i++)
        {
            res[0][i] = i;
        }
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                int t = (word1[i - 1] == word2[j - 1] ? 0 : 1);
                res[i][j] = min(res[i][j - 1] + 1, min(res[i - 1][j] + 1, res[i - 1][j - 1] + t));
            }
        }
        return res[m][n];
    }
};