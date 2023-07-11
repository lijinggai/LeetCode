class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        //func(i)=MAX(func(i-1)+arr[i-1],arr[i-1])
        int MAX = array[0], num = 0;
        for (size_t i = 0; i < array.size(); i++)
        {
            num = max(num + array[i], array[i]);
            if (MAX < num)
                MAX = num;
        }
        return MAX;
    }
};