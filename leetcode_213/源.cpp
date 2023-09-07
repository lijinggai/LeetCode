class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> res(n + 1, 0);
        res[1] = nums[0]; res[2] = nums[1];
        int ans = max(nums[0], nums[1]);
        if (n == 2)
            return ans;
        //不盗取最后家，求最大金额
        for (int i = 3; i < n; i++)
        {
            if (i == 3)
                res[i] = nums[i - 1] + res[i - 2];
            else
            {
                res[i] = nums[i - 1] + max(res[i - 2], res[i - 3]);
            }
            ans = max(ans, res[i]);
        }
        //不盗取第一家，求最大金额
        res[1] = nums[1], res[2] = nums[2];
        ans = max(ans, nums[2]);
        for (int i = 3; i < n; i++)
        {
            if (i == 3)
                res[i] = nums[i] + res[i - 2];
            else
            {
                res[i] = nums[i] + max(res[i - 2], res[i - 3]);
            }
            ans = max(ans, res[i]);
        }
        return ans;
    }
};