class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size(), m = groups.size(), k = 0;
        for (int i = 0; i < m;)
        {
            int length = groups[i].size();
            if (k + length > n)
                return false;
            int j = 0;
            for (j = 0; j < length; j++)
            {
                if (groups[i][j] != nums[k + j])
                    break;
            }
            if (j == length) {
                i++; k += length;
            }
            else
                k++;
        }
        return true;
    }
};