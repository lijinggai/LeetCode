class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = points.size(), m = queries.size();
        vector<int> ans(m, 0);
        for (int i = 0; i < m; i++)
        {
            int x = queries[i][0], y = queries[i][1], r = queries[i][2], tmp = 0;
            for (int j = 0; j < n; j++)
            {
                int px = points[j][0], py = points[j][1];
                if (((x - px) * (x - px) + (y - py) * (y - py)) <= r * r)
                    tmp++;
            }
            ans[i] = tmp;
        }
        return ans;
    }
};