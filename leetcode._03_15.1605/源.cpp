class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                //选行列小的一个插入v;
                int tmp = min(rowSum[i], colSum[j]);
                res[i][j] = tmp;
                //每一个数都是行列的一部分，减去小的那个大的一个一定够用
                rowSum[i] -= tmp;
                colSum[j] -= tmp;
            }
        }
        return res;
    }
};