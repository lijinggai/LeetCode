class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), answer = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            for (int j = i; nums[j] != n;)
            {
                int tmp = nums[j];
                nums[j] = n;
                j = tmp;
                count++;
            }
            answer = max(answer, count);
        }
        return answer;
    }
};