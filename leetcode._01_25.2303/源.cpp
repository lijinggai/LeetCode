class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        int prev = 0;
        for (int i = 0; i < brackets.size(); i++)
        {
            if (income > brackets[i][0])
            {
                ans += (double)((brackets[i][0] - prev) * brackets[i][1] / 100.0);
            }
            else
            {
                ans += (double)((income - prev) * brackets[i][1] / 100.0);
                break;
            }
            prev = brackets[i][0];
        }
        return ans;
    }
};