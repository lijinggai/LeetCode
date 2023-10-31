class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set hash(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int tmp = nums[i] - 1, count = 1;
            while (true)
            {

                if (hash.find(tmp) != hash.end()) {
                    count++;
                    hash.erase(tmp);
                }
                else {
                    break;
                }
                tmp--;
            }

            tmp = nums[i] + 1;
            while (true)
            {
                if (hash.find(tmp) != hash.end()) {
                    count++;
                    hash.erase(tmp);
                }
                else {
                    break;
                }
                tmp++;
            }

            ans = max(ans, count);
        }
        return ans;
    }
};