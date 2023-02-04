class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int n = 0, m = matrix[0].size() - 1;
        while (n < matrix.size() && m >= 0)
        {
            if (matrix[n][m] > target)
                m--;
            else if (matrix[n][m] < target)
                n++;
            else
                return true;
        }
        return false;
    }
};