class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        while (n != 0)
        {
            //һ����ģ���Լ�-1�������ƻ����һ��1��
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};