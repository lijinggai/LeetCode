class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1, len = prices.size(), ans = 0;
        if (len == 1)
            return 0;
        while (right < len)
        {
            if (prices[left] > prices[right])
            {
                left = right;
            }
            ans = max(ans, prices[right] - prices[left]);
            right++;
        }
        return ans;
    }
};