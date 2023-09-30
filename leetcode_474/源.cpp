class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int num = strs.size();
        //n为多少个1，m为多少个0
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        int ans = 1;
        for (auto& s : strs)
        {
            //有多少个1和0；
            int row = 0, col = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '1')
                    row++;
                else
                    col++;
            }
            //
            for (int i = n; i >= row; i--)
            {
                for (int j = m; j >= col; j--)
                {
                    if (dp[i - row][j - col] != 0)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - row][j - col] + 1);
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }
        // for(auto &v:dp)
        // {
        //     for(int i=0;i<m+1;i++)
        //     {
        //         cout<<v[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans - 1;
    }
};