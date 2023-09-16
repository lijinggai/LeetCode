//ƥ�䣺f(i,j)=f(i-1,j-1)
//��ƥ�䣺f(i,j)=max��f(i-1,j)��f(i,j-1)��+1;
//"" s e a
//e  2 1 2
//a  3 2 1
//t  4 3 
//����ƥ��ʱ,��ǰ�ڵ����ߺ��ϱ���ƥ��ģ�����߻����ϱߵ���ǰλ�þ��Ǿ�������һ���ַ���ɾ������ַ���һ�β���
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //��ʼ����
        for (int i = 1; i < m + 1; i++)
            dp[i][0] = i;

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (i == 0) {
                    dp[i][j] = j;
                }
                else {
                    if (word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};