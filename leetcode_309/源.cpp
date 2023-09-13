class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        //0.不持股，当天也没有出售，dp[i][0]=max(前一天出售，前一天没有出售)
        //1.不持股，当天出售，dp[i][1]=前一天没有出售，有冷却期+当天价格
        //2.持股，当天买入，非当天，dp[i][1]=max(前一天不持股且没有出售-当天价格,前一天不持股且没有出售)
        dp[1][0] = 0, dp[1][1] = 0, dp[1][2] = -prices[0];
        for (int i = 2; i < n + 1; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][2] + prices[i - 1];
            dp[i][2] = max(dp[i - 1][0] - prices[i - 1], dp[i - 1][2]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};