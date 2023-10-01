class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        //f(i,j)=max(piles[i-1]-dp[i+1][j],piles[j-1]-dp[i][j-1])
        //1.选left算出left+1,right
        //1.选right算出left,right-1
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i < n + 1; i++)
        {
            dp[i][i] = piles[i - 1];
        }
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < n + 1; j++)
            {
                dp[i][j] = max(piles[i - 1] - dp[i + 1][j], piles[j - 1] - dp[i][j - 1]);
            }
        }
        return dp[1][n] >= 0;
    }
};