class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        vector<vector<int>> filter;
        //specilΪ�գ�ĳ����Ʒ�����������������ڵ����
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
        //����۸�
        int minSum = 0;
        for (int i = 0; i < n; i++)
        {
            minSum += price[i] * curNeeds[i];
        }
        if (minSum == 0)
            return minSum;

        //����������
        for (auto& fs : filterSpecial)
        {
            int fSum = 0;
            vector<int> nextNeeds;
            for (int i = 0; i < n; i++)
            {
                //���ĳ���������
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