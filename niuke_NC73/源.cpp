class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 0;
        int val = 0;
        //ռһ��࣬1:1��ô�ض�ʣ�µ���ռһ����Ǹ�
        for (int i = 0; i < numbers.size(); i++)
        {
            if (count == 0)
            {
                val = numbers[i];
                count++;
            }
            else
            {
                if (val == numbers[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        return val;
    }
};