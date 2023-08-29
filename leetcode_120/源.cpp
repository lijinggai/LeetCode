class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //任意位置的最小路径和
        //f(i,j)=f(i,j)+min(f(i+1,j),f(i+1,j+1))
        int n = triangle.size();
        vector<int> res(triangle[n - 1].begin(), triangle[n - 1].end());
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < i + 1; j++)
            {
                res[j] = triangle[i][j] + min(res[j], res[j + 1]);
            }
        }
        return res[0];
    }
};