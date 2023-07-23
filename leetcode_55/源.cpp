class Solution {
public:
    bool canJump(vector<int>& nums) {
        int limit = nums[0];
        bool res = false;
        //位置是能到的位置，所以判断要加1
        for (int i = 0; i < limit + 1; i++)
        {
            //能跳到更远的位置，更新
            if (nums[i] + i > limit)
                limit = nums[i] + i;
            //能跳到最后一个位置或更后面结束
            if (limit >= nums.size() - 1)
            {
                res = true;
                break;
            }
        }
        return res;
    }
};