class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return false;
        //���ܺ�
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        //����������
        if (total % 2 == 1)
            return false;
        else
            total /= 2;
        vector<bool> dp(total + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = total; j >= 1; j--)
            {
                //����Ԫ��С�ڵ���j���м����ֵ
                if (nums[i] <= j)
                {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
            //����Ԫ�ؿ�����ϳ�total
            if (dp[total])
                return true;
        }
        return false;
    }
};