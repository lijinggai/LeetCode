class Solution {
public:
    int rob(vector<int>& nums) {
        //�����⣺��ȡ��n������ʱ�������
        //f(i,j)=nums[i-1]+max(f(i,j-2),f(i,j-3)); j>3
        //���ٸ�һ�����䣬������j-2,�����������������j-3��������࣬����2 111 2��ѡ���м��1���Ի�ȡ�����ֵ����������j-2��һ�����
        int n = nums.size();
        if (n == 1)
            return nums[0];
        // vector<vector<int>> res(n+1,vector<int>(n+1,0));
        // res[1][1]=nums[0];
        // res[2][1]=nums[0];
        // res[2][2]=nums[1];
        // for(int i=3;i<n+1;i++)
        // {
        //     for(int j=1;j<=i;j++)
        //     {
        //         if(j<i)
        //         {
        //             res[i][j]=res[i-1][j];
        //         }
        //         else if(j==i)
        //         {
        //             if(i==3)
        //             {
        //                 res[i][j]=nums[i-1]+res[i][j-2];
        //             }
        //             else
        //                res[i][j]=nums[i-1]+max(res[i][j-2],res[i][j-3]); 
        //         }

        //     }
        // }
        // int ans=res[n][1];
        //��ʹ�ö�ά���飬ʹ����������Ҳ����
        vector<int> res(n + 1, 0);
        res[1] = nums[0], res[2] = nums[1];
        int ans = max(nums[0], nums[1]);
        for (int i = 3; i < n + 1; i++)
        {
            if (i == 3)
                res[i] = nums[i - 1] + res[i - 2];
            else
                res[i] = nums[i - 1] + max(res[i - 2], res[i - 3]);
            ans = max(ans, res[i]);
        }
        return ans;
    }
};