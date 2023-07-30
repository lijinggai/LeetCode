class Solution {
private:
    int Total(vector<vector<int>>& grid, int r, int c)
    {
        int total = 4;
        //����������½�ؾ���-1
        if (r + 1 < grid.size())
        {
            if (grid[r + 1][c] == 1)
                total--;
        }
        if (r - 1 >= 0)
        {
            if (grid[r - 1][c] == 1)
                total--;
        }
        if (c + 1 < grid[0].size())
        {
            if (grid[r][c + 1] == 1)
                total--;
        }
        if (c - 1 >= 0)
        {
            if (grid[r][c - 1] == 1)
                total--;
        }
        return total;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                //½��ִ�к���
                if (grid[i][j] == 1)
                    total += Total(grid, i, j);
            }
        }
        return total;
    }
};