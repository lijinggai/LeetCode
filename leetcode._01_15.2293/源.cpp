class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size() / 2;
        while (nums.size() != 1)
        {
            vector<int> v(n);
            for (int i = 0; i < v.size(); i++)
            {
                if (i % 2 == 0)
                    v[i] = min(nums[2 * i], nums[2 * i + 1]);
                else
                    v[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
            nums = v;
            n /= 2;
        }
        return nums[0];
    }
};