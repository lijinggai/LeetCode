class Solution {
public:
    int countSubstrings(string s) {
        //µ¥¸ö×Ö·û
        int ans = s.size(), n = s.size();
        //f(i,j)=f(i-1,j+1)+2 s[i]==s[j]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 2; i < n + 1; i++)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (s[i - 1] == s[j - 1])
                {
                    if (i - j < 3)
                    {
                        dp[i][j]++;
                        ans++;
                    }
                    else
                    {
                        if (dp[i - 1][j + 1])
                        {
                            dp[i][j]++;
                            ans++;
                        }
                    }

                }
            }
        }
        return ans;
    }
};