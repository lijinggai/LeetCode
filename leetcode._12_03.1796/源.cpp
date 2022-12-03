class Solution {
public:
    int secondHighest(string s) {
        int min = -1, max = -1;
        for (auto e : s)
        {
            if (e >= '0' && e <= '9')
            {
                int cmp = e - '0';
                if (min == -1)
                    min = cmp;
                if (min != -1 && max == -1)
                {
                    if (cmp != min)
                    {
                        if (cmp > min)
                            max = cmp;
                        else {
                            max = min;
                            min = cmp;
                        }
                    }
                }
                if (min != -1 && max != -1 && min != cmp && max != cmp)
                {
                    if (cmp > min)
                    {
                        if (cmp < max)
                        {
                            min = cmp;
                        }
                        if (cmp > max)
                        {
                            min = max;
                            max = cmp;
                        }
                    }
                }
            }
        }
        return min != -1 && max != -1 ? min : -1;
    }
};