class Solution {
    //   b b b a b
    // b 1
    // b 2 1
    // b 3 2 1
    // a 3 2 1 1
    // b 4 3 3 1  1 
    //f(i,j)=f(i-1,j-1)+2 s[i]==s[j]
    //f(i,j)=max(f(i-1,j),f(i,j+1)); s[i]!=s[j]
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        //只有一个元素
        for (int i = 1; i < n + 1; i++)
        {
            dp[i][i] = 1;
        }
        for (int i = 2; i < n + 1; i++)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j + 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[n][1];
    }
};