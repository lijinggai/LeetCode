//������(n/2)*(n/2+1)  ��������4������ֵ����
//ż����(n/2)*(n/2)
//2 3 4 5 6 7   8  9  10 
//1 2 4 6 9 12 18  24 36
//             3*5   4*5 5*5  //�۲���Եó���5��ʼ����ֽ�������
//         ����3*6 4*6  6*6���5��
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        for (int i = 2; i < n + 1; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                int num1 = max(j, dp[j]);
                int num2 = max(i - j, dp[i - j]);
                dp[i] = max(dp[i], num1 * num2);
            }
        }
        return dp[n];
    }
};