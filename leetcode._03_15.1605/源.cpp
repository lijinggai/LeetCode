class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                //ѡ����С��һ������v;
                int tmp = min(rowSum[i], colSum[j]);
                res[i][j] = tmp;
                //ÿһ�����������е�һ���֣���ȥС���Ǹ����һ��һ������
                rowSum[i] -= tmp;
                colSum[j] -= tmp;
            }
        }
        return res;
    }
};