class Solution {
public:
    int beautySum(string s) {
        int ret = 0, n = s.size();
        for (int i = 0; i < n - 1; i++)
        {
            unordered_map<int, int> m;
            for (int j = i; j < n; j++)
            {
                m[s[j] - '0']++;
                int Min = n, Max = 0;
                for (auto e : m)
                {
                    Max = max(Max, e.second);
                    Min = min(Min, e.second);
                }
                ret += Max - Min;
            }
        }
        return ret;
    }
};