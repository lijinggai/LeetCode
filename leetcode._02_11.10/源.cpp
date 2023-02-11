class Solution {
public:
    int numWays(int n) {
        int n1 = 1, n2 = 2, ans = 1, MOD = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                ans = 1;
            if (i == 2)
                ans = 2;
            if (i > 2)
            {
                ans = (n1 + n2) % MOD;
                n1 = n2;
                n2 = ans;
            }
        }
        return ans;
    }
};