class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Maxp = nums[0], Minp = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int maxt = Maxp, mint = Minp;
            Maxp = max(nums[i], max(nums[i] * maxt, nums[i] * mint));//选择当前最大
            Minp = min(nums[i], min(nums[i] * mint, nums[i] * maxt));//选这当前最小
            ans = max(ans, Maxp);
        }
        return ans;
    }
};