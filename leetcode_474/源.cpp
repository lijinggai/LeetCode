class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int num = strs.size();
        //nΪ���ٸ�1��mΪ���ٸ�0
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        int ans = 1;
        for (auto& s : strs)
        {
            //�ж��ٸ�1��0��
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