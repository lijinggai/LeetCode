vector<vector<int>> dire = { {1,0},{0,1},{-1,0},{0,-1} };
int MOD = 1e9 + 7;
class Solution {
    int DFS(int& m, int& n, int curMove, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>& memo)
    {
        if (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n)
            return 1;
        if (curMove == maxMove)
            return 0;
        if (memo[startRow][startColumn][curMove] != -1)
            return memo[startRow][startColumn][curMove];
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            ans = (ans + DFS(m, n, curMove + 1, maxMove, startRow + dire[i][0], startColumn + dire[i][1], memo)) % MOD;
        }
        memo[startRow][startColumn][curMove] = ans;
        return ans;

    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove, -1)));

        return DFS(m, n, 0, maxMove, startRow, startColumn, memo);
    }
private:
};