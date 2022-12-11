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
            //�Ƚ������ٻ�����
            swap(nums[start], nums[i]);
            //+1��ʾ��һ����ִ��һ��
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