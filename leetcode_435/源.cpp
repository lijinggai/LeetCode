bool cmp(vector<int>& v1, vector<int>& v2)
{
    return v1[1] < v2[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int right = intervals[0][1];
        int count = 0;
        //优先使用先结束的，剩余的空间更多
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < right)
                count++;
            //实时更新当前使用到什么位置了
            else
                right = intervals[i][1];
        }
        return count;

    }
};