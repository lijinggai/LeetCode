class Solution {
public:
    int jumpFloor(int number) {
        if (number == 1)
            return 1;
        int first = 1, second = 1;
        for (int i = 2; i <= number; i++)
        {
            int t = first + second;
            first = second;
            second = t;
        }
        return second;
    }
};