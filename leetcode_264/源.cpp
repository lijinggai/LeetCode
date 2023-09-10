class Solution {
public:
    int nthUglyNumber(int n) {
        //f(i)=min(2*index2,min(3*index3,5*index3));
        if (n < 6)
            return n;
        vector<int> res(n + 1, 0);
        for (int i = 1; i < 6; i++)
            res[i] = i;
        int num2 = 3, num3 = 3, num5 = 5;
        for (int i = 6; i < n + 1; i++)
        {
            int total2 = 2 * res[num2];
            int total3 = 3 * res[num3];
            int total5 = 5 * res[num5];
            //相当于去重，比如：2*6=12,3*4=12
            if (total2 <= res[i - 1])
                total2 = 2 * res[++num2];
            if (total3 <= res[i - 1])
                total3 = 3 * res[++num3];
            if (total5 <= res[i - 1])
                total5 = 5 * res[++num5];
            res[i] = min(total2, min(total3, total5));
            //最小的值下标++
            if (total2 == res[i])
                num2++;
            if (total3 == res[i])
                num3++;
            if (total5 == res[i])
                num5++;
        }
        return res[n];
    }
};