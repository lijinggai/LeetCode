class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        int k = 0;
        int dp[26] = { 0 };
        for (int i = 0; i < n; i++)
        {
            //-25和1要处理
            if (i && (s[i] - s[i - 1] + 26) % 26 == 1)
                k++;
            else
                k = 1;
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], k);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans += dp[i];
        }
        return ans;
    }
};