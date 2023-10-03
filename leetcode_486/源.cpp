// class Solution {
//     int DFS(int l,int r,vector<int> &nums,vector<vector<int>> &memo)
//     {
//         if(l>r)
//             return 0;
//         if(memo[l][r]!=INT_MAX)
//             return memo[l][r];
//         //1-(5-2)=1-5+2
//         int cur1=nums[l]-DFS(l+1,r,nums,memo);
//         int cur2=nums[r]-DFS(l,r-1,nums,memo);

//         return max(cur1,cur2);
//     }
// public:
//     bool PredictTheWinner(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> memo(n,vector<int>(n,INT_MAX));
//         return DFS(0,n-1,nums,memo)>=0;

//     }
// };
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < n + 1; i++)
        {
            dp[i][i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < n + 1; j++)
            {
                dp[i][j] = max(nums[i - 1] - dp[i + 1][j], nums[j - 1] - dp[i][j - 1]);
            }
        }
        return dp[1][n] >= 0;

    }
};