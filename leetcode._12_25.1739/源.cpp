class Solution {
public:
    int minimumBoxes(int n) {
        int sum = 1, i = 1;
        while (sum < n)
        {
            n -= sum;
            i++;
            sum += i;
        }
        sum = 1; int j = 1;
        while (sum < n)
        {
            n -= sum;
            j++;
            sum++;
        }
        return i * (i - 1) / 2 + j;
    }
};