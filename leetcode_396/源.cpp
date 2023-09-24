class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        //����Ԫ��֮��
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            res += i * nums[i];
            total += nums[i];
        }
        //ɾ��Ԫ��
        int dele = n - 1;
        int tmp = res;
        while (dele > 0)
        {
            tmp = tmp + total - (n - 1 + 1) * nums[dele];
            res = max(res, tmp);
            dele--;
        }
        return res;
    }
};