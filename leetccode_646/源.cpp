class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 0)
            return 0;
        //需要按结束时间来排序，先结束的 会给后面留出更多的距离
        sort(pairs.begin(), pairs.end(), Cmp);
        int ans = 1, cur = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++)
        {
            if (pairs[i][0] > cur)
            {
                cur = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
    //做为成员函数，不能包含this指针
    static bool Cmp(vector<int>& v1, vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
};