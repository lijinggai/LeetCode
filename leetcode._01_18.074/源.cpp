class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& l, const vector<int>& r)->bool {
                return l[0] < r[0];
            });
        vector<vector<int>> v;
        vector<int> vtmp;
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                if (intervals[i - 1][1] < intervals[i][0])
                {
                    v.push_back(intervals[i - 1]);
                    v.push_back(intervals[i]);
                }
                else
                {
                    vtmp.push_back(intervals[i - 1][0]);
                    vtmp.push_back(max(intervals[i][1], intervals[i - 1][1]));
                    cout << vtmp[0] << vtmp[1];
                    v.push_back(vtmp);
                }
            }
            else {
                if (intervals[i - 1][1] < intervals[i][0])
                    v.push_back(intervals[i - 1]);
                else
                {
                    int tmp = i, maxnum = intervals[tmp - 1][1];
                    vector<int> vtmp(1, intervals[i - 1][0]);
                    while (tmp < n && maxnum >= intervals[tmp][0])
                    {
                        maxnum = max(maxnum, intervals[tmp][1]);
                        tmp++;
                    }
                    i = tmp;
                    vtmp.push_back(maxnum);
                    v.push_back(vtmp);
                    if (i == n - 1)
                    {
                        v.push_back(intervals[n - 1]);
                    }
                }
            }
        }
        return v;
    }
};