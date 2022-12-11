class Solution {
public:
    void BackTrack(vector<vector<int>>& vv, vector<int>& nums, int start, int end)
    {
        if (start == end)
        {
            vv.push_back(nums);
            return;
        }
        for (int i = start; i < end; i++)
        {
            //先交换，再换回来
            swap(nums[start], nums[i]);
            //+1表示下一层少执行一次
            BackTrack(vv, nums, start + 1, end);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vv;
        BackTrack(vv, nums, 0, (int)nums.size());
        return vv;
    }
};