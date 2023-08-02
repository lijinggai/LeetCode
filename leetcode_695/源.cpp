vector<vector<int>> direction{ {1,0},{-1,0},{0,-1},{0,1} };//上下左右
class Solution {
private:
    int DFS(vector<vector<int>>& grid, int row, int col, const int& n, const int& m)
    {
        if (grid[row][col] == 0)
            return 0;
        grid[row][col] = 0;
        //自己
        int count = 1;
        for (int i = 0; i < direction.size(); i++)
        {
            if (direction[i][0] != 0)
            {
                if (row + direction[i][0] >= 0 && row + direction[i][0] < n)
                    count += DFS(grid, row + direction[i][0], col, n, m);
            }
            else
            {
                if (col + direction[i][1] >= 0 && col + direction[i][1] < m)
                    count += DFS(grid, row, col + direction[i][1], n, m);
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int Mcount = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    Mcount = max(Mcount, DFS(grid, i, j, n, m));
                }
            }
        }
        return Mcount;
    }
};