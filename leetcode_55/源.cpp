class Solution {
public:
    bool canJump(vector<int>& nums) {
        int limit = nums[0];
        bool res = false;
        //λ�����ܵ���λ�ã������ж�Ҫ��1
        for (int i = 0; i < limit + 1; i++)
        {
            //��������Զ��λ�ã�����
            if (nums[i] + i > limit)
                limit = nums[i] + i;
            //���������һ��λ�û���������
            if (limit >= nums.size() - 1)
            {
                res = true;
                break;
            }
        }
        return res;
    }
};