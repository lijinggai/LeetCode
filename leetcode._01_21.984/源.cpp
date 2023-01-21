class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int maxnum = a, minnum = b;
        char maxch = 'a', minch = 'b';
        if (maxnum < minnum)
        {
            maxnum = b; minnum = a;
            maxch = 'b'; minch = 'a';
        }
        string s;
        while (minnum)
        {
            if (maxnum > minnum)
            {
                s += maxch;
                maxnum--;
            }
            s += maxch;
            s += minch;
            maxnum--; minnum--;
        }
        while (maxnum > 0)
        {
            s += maxch;
            maxnum--;
        }
        return s;
    }
};