class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 10;
        int t = 9;
        for (int i = 2; i < n + 1; i++)
        {
            t *= (10 - i + 1);
            dp[i] = dp[i - 1] + t;
        }
        return dp[n];
    }
};