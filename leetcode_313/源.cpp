class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //解题思路：primes的所有元素都从第一个丑数相乘，选择小的那个做为丑数序列的当前元素
        vector<long long> dp(n + 1, 0);
        //第一个丑数是1
        dp[1] = 1;
        int m = primes.size();
        //每一个质因数是dp数组的每个元素，1为第一个元素
        vector<int> index(m, 1);
        for (int i = 2; i < n + 1; i++)
        {
            long long minN = INT_MAX;
            //找最小
            for (int j = 0; j < m; j++)
            {
                minN = min(minN, primes[j] * dp[index[j]]);
            }
            dp[i] = minN;
            //下一个位置，也有去重的作用
            for (int j = 0; j < m; j++)
            {
                if (primes[j] * dp[index[j]] == dp[i])
                    index[j]++;
            }
        }
        return dp[n];
    }
};