class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        vector<int> dp(n + 1, 0);
        //与前一个的差值
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = nums[i - 1] - nums[i - 2];
        }
        int left = 2, right = 2;
        int res = 0;
        //如果差值大于1，结果+=distance!;
        while (right < n + 1)
        {
            if (dp[left] == dp[right])
                right++;
            else
            {
                int distance = right - left;
                if (distance >= 2)
                {
                    for (int i = distance - 1; i > 0; i--)
                    {
                        res += i;
                    }
                }
                left = right;
                right++;
            }
        }
        //是一个阶乘
        int distance = right - left;
        if (distance >= 2)
        {
            for (int i = distance - 1; i > 0; i--)
            {
                res += i;
            }
        }
        return res;
    }
};