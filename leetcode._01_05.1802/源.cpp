class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            long numSum = mid + Cal(index, mid - 1) + Cal(n - index - 1, mid - 1);
            if (numSum > maxSum)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l - 1;
    }
    long Cal(int length, int Max)
    {
        if (Max + 1 > length)
            return (long)(Max + 1 - length + Max) * length / 2;
        else
        {
            long tmp = (length - Max);
            return (long)(Max + 1) * Max / 2 + tmp;
        }
    }
};