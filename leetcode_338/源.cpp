class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            int t = i;
            while (t)
            {
                t = t & (t - 1);
                res[i]++;
            }
        }
        return res;
    }
};