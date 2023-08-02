vector<vector<int>> direction{ {1,0},{-1,0},{0,-1},{0,1} };//上下左右
class Solution {
private:
    void DFS(vector<vector<char>>& grid, int row, int col, int& n, int& m)
    {
        if (grid[row][col] != '1')
            return;
        grid[row][col] = '0';
        for (int i = 0; i < direction.size(); i++)
        {
            if (direction[i][0] != 0)
            {
                if (row + direction[i][0] >= 0 && row + direction[i][0] < n)
                    DFS(grid, row + direction[i][0], col, n, m);
            }
            else
            {
                if (col + direction[i][1] >= 0 && col + direction[i][1] < m)
                    DFS(grid, row, col + direction[i][1], n, m);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;//数量
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                //把岛屿变成‘0’
                if (grid[i][j] == '1')
                {
                    DFS(grid, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};