class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        //0.���ֹɣ�����Ҳû�г��ۣ�dp[i][0]=max(ǰһ����ۣ�ǰһ��û�г���)
        //1.���ֹɣ�������ۣ�dp[i][1]=ǰһ��û�г��ۣ�����ȴ��+����۸�
        //2.�ֹɣ��������룬�ǵ��죬dp[i][1]=max(ǰһ�첻�ֹ���û�г���-����۸�,ǰһ�첻�ֹ���û�г���)
        dp[1][0] = 0, dp[1][1] = 0, dp[1][2] = -prices[0];
        for (int i = 2; i < n + 1; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][2] + prices[i - 1];
            dp[i][2] = max(dp[i - 1][0] - prices[i - 1], dp[i - 1][2]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};