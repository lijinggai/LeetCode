class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while (n != 0)
        {
            //一个数模上自己-1；二进制会减少一个1；
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};