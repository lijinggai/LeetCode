class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return false;
        //算总和
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        //奇数不可能
        if (total % 2 == 1)
            return false;
        else
            total /= 2;
        vector<bool> dp(total + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = total; j >= 1; j--)
            {
                //数组元素小于等于j才有计算价值
                if (nums[i] <= j)
                {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
            //数组元素可以组合成total
            if (dp[total])
                return true;
        }
        return false;
    }
};