class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Maxp = nums[0], Minp = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int maxt = Maxp, mint = Minp;
            Maxp = max(nums[i], max(nums[i] * maxt, nums[i] * mint));//ѡ��ǰ���
            Minp = min(nums[i], min(nums[i] * mint, nums[i] * maxt));//ѡ�⵱ǰ��С
            ans = max(ans, Maxp);
        }
        return ans;
    }
};