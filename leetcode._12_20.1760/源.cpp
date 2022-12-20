class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 1e9;
        int ans = 0;
        while (left <= right) {
            int y = (left + right) / 2;
            long long ops = 0;
            for (int x : nums) {
                ops += (x - 1) / y;
            }
            if (ops <= maxOperations) {
                ans = y;
                right = y - 1;
            }
            else {
                left = y + 1;
            }
        }
        return ans;
    }
};