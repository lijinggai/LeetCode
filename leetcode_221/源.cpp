class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //f(i,j)=min(f(i,j-1),min(f(i-1,j),f(i-1,j-1)))+1  ��ǰ�ڵ�Ϊ�����ε����½�
        //ľͰЧӦ������ѡ���
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i != 0 && j != 0)
                {
                    if (matrix[i][j] == '1')
                        res[i][j] = min(res[i - 1][j], min(res[i][j - 1], res[i - 1][j - 1])) + 1;
                }
                else
                    res[i][j] = matrix[i][j] - '0';
                ans = max(ans, res[i][j]);
            }
        }
        return ans * ans;
    }
};