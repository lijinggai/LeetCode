class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int num = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (k - num <= 25 && k - num > 0)
            {
                ans[i] += k - num;
                break;
            }
            else if (k - num > 25)
            {
                ans[i] += 25;
                k -= 25;
            }
            else
                break;
        }
        return ans;
    }
};