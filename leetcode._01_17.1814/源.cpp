class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int index = 0, ans = 0, MOD = 1e9 + 7;
        for (int i : nums)
        {
            int tmp = 0;
            while (i)
            {
                tmp = tmp * 10 + i % 10;
                i /= 10;
            }
            m[nums[index++] - tmp]++;
        }
        for (const pair<int, int>& e : m)
        {
            int tmp = e.second;
            while (tmp != 0)
            {
                tmp--;
                ans = (ans + tmp) % MOD;
            }
        }
        return ans;
    }
};