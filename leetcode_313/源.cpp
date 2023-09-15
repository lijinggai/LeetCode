class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //����˼·��primes������Ԫ�ض��ӵ�һ��������ˣ�ѡ��С���Ǹ���Ϊ�������еĵ�ǰԪ��
        vector<long long> dp(n + 1, 0);
        //��һ��������1
        dp[1] = 1;
        int m = primes.size();
        //ÿһ����������dp�����ÿ��Ԫ�أ�1Ϊ��һ��Ԫ��
        vector<int> index(m, 1);
        for (int i = 2; i < n + 1; i++)
        {
            long long minN = INT_MAX;
            //����С
            for (int j = 0; j < m; j++)
            {
                minN = min(minN, primes[j] * dp[index[j]]);
            }
            dp[i] = minN;
            //��һ��λ�ã�Ҳ��ȥ�ص�����
            for (int j = 0; j < m; j++)
            {
                if (primes[j] * dp[index[j]] == dp[i])
                    index[j]++;
            }
        }
        return dp[n];
    }
};