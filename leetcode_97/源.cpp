class Solution {
    //Ӧ��ʹ�ù�����ȼ�����������һ��
    void DFS(vector<vector<bool>>& res, string& s1, string& s2, string& s3, int t, int i, int j)
    {
        //���ܳ���res����
        if (i >= s1.size() + 1 || j >= s2.size() + 1)
            return;
        //����ʹ������һ��Ԫ�أ���Խs1����
        if (i < s1.size() && s1[i] == s3[t] && res[i + 1][j] == false)
        {
            res[i + 1][j] = true;
            DFS(res, s1, s2, s3, t + 1, i + 1, j);
        }

        if (j < s2.size() && s2[j] == s3[t] && res[i][j + 1] == false)
        {
            res[i][j + 1] = true;
            DFS(res, s1, s2, s3, t + 1, i, j + 1);
        }
        return;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        //s1��ǰn���ֺ�s2��ǰm���ֿ��Թ���s3��ǰn+m������
        //f(i,j)=f(i-1,j)||f(i,j-1)
        int m = s1.size(), n = s2.size(), total = s3.size();
        if (m + n != total)
            return false;
        vector<vector<bool>> res(m + 1, vector<bool>(n + 1, false));
        res[0][0] = true;
        DFS(res, s1, s2, s3, 0, 0, 0);
        return res[m][n];
    }
};