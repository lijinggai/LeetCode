class Solution {
    void DFS(vector<int>& nums, int index, int& count, int target, int cur)
    {
        if (index == nums.size())
        {
            if (cur == target)
                count++;
            return;
        }
        DFS(nums, index + 1, count, target, cur + nums[index]);
        DFS(nums, index + 1, count, target, cur - nums[index]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        DFS(nums, 0, count, target, 0);
        return count;
    }
};