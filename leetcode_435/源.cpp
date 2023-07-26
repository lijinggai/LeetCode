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
        //����ʹ���Ƚ����ģ�ʣ��Ŀռ����
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < right)
                count++;
            //ʵʱ���µ�ǰʹ�õ�ʲôλ����
            else
                right = intervals[i][1];
        }
        return count;

    }
};