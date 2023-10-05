class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        int num1 = 1, num2 = 1;
        for (int i = 2; i <= n - 1; i++)
        {
            int tmp = num2;
            num2 += num1;
            num1 = tmp;
        }
        return num2;
    }
};