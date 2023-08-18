class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //f(i)=max(maxRes,max(nums[i],prev+nums[i]));ѡ��ǰ���ֵ����ǰ���ֵ+��ǰ��ֵ
        int maxRes = nums[0];
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prev = max(nums[i], prev + nums[i]);
            maxRes = max(maxRes, prev);
        }
        return maxRes;
    }
};