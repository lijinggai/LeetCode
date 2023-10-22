class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        vector<vector<int>> filter;
        //specil为空，某个商品大于需求，礼包结果大于单买的
        for (int i = 0; i < special.size(); i++)
        {
            int total = 0;
            for (int j = 0; j < n; j++)
            {
                if (special[i][j] > needs[j])
                {
                    total = 0;
                    break;
                }
                total += special[i][j] * price[j];
            }
            if (total != 0 && total > special[i][n])
                filter.push_back(special[i]);
        }

        return dfs(price, filter, needs, n);
    }
    int dfs(vector<int>& price, vector<vector<int>>& filterSpecial, vector<int>& curNeeds, int n)
    {
        //单买价格
        int minSum = 0;
        for (int i = 0; i < n; i++)
        {
            minSum += price[i] * curNeeds[i];
        }
        if (minSum == 0)
            return minSum;

        //购买礼包结果
        for (auto& fs : filterSpecial)
        {
            int fSum = 0;
            vector<int> nextNeeds;
            for (int i = 0; i < n; i++)
            {
                //礼包某项大于需求
                if (curNeeds[i] >= fs[i])
                    nextNeeds.push_back(curNeeds[i] - fs[i]);
                fSum = price[i] * fs[i];
            }
            if (nextNeeds.size() == n)
                minSum = min(minSum, dfs(price, filterSpecial, nextNeeds, n) + fs[n]);

        }
        return minSum;

    }
};