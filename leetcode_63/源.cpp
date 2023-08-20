class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            //石头不可能走到这
            if (obstacleGrid[i][0] == 1)
            {
                while (i < m)
                    res[i++][0] = 0;
            }
            else
                res[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            //石头不可能走到这
            if (obstacleGrid[0][i] == 1)
                while (i < n)
                    res[0][i++] = 0;
            else
                res[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    res[i][j] = 0;
                else
                    res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }
        return res[m - 1][n - 1];
    }
};