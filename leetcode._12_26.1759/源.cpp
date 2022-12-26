class Solution {
public:
    int countHomogenous(string s) {
        map<long long, int> m;
        long long count = 1;
        int n = s.size(), mod = 1e9 + 7;
        for (int i = 1, j = 0; j < n; j++, i++)
        {
            if (j == n - 1)
            {
                m[count]++;
                break;
            }
            if (s[i] == s[j])
            {
                count++;
            }
            else
            {
                m[count]++;
                count = 1;
            }
        }
        int ans = 0;
        for (auto e : m)
        {
            if (e.first == 1)
                ans = (ans + e.second) % mod;
            else
            {
                ans += ((e.first + 1) * e.first / 2 * e.second) % mod;
            }
        }
        return ans;
    }
};