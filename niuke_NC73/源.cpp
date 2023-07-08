class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 0;
        int val = 0;
        //占一半多，1:1那么必定剩下的是占一半的那个
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