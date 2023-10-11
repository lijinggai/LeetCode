class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)
            return n;
        int num1 = 1, num2 = 2;
        for (int i = 3; i <= n; i++)
        {
            int tmp = num2;
            num2 += num1;
            num1 = tmp;
        }
        return num2;
    }
};