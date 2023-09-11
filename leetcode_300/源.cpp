class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //第n个的最大递增长度
        //f(i)=f(i-j)+1 1<=j<i && nums[i-1]>nums[j-1]
        int n = nums.size();
        vector<int> res(n + 1, 1);
        int maxAns = 1;
        for (int i = 2; i < n + 1; i++)
        {
            for (int j = i - 1; j > 0; j--)
            {
                if (nums[i - 1] > nums[j - 1])
                {
                    res[i] = max(res[i], res[j] + 1);
                }
            }
            maxAns = max(maxAns, res[i]);
        }
        return maxAns;
    }
};