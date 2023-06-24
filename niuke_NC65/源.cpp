class Solution {
public:
    int Fibonacci(int n) {
        if (n == 1 || n == 2)
            return 1;
        int first = 1, second = 1;
        for (int i = 3; i <= n; i++) {
            int t = first + second;
            first = second;
            second = t;
        }
        return second;
    }
};