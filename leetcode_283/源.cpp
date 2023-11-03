class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroNum = 0, n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zeroNum++;
        }
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0) {
                if (pos != i) {
                    nums[pos++] = nums[i];
                    nums[i] = 0;
                }
                else
                    pos++;
            }
        }
        //for(int i=zeroNum-1; i<n; i++)
        //    nums[i]=0;
    }
};