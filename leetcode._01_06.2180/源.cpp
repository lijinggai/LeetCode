class Solution {
public:
    int countEven(int num) {
        int count = 0;
        for (int i = 1; i <= num; i++)
        {
            int tmp = i, tem = 0;
            while (tmp)
            {
                tem += tmp % 10;
                tmp /= 10;
            }
            if (tem % 2 == 0)
                count++;
        }
        return count;
    }
};