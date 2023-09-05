class Solution {
public:
    int rob(vector<int>& nums) {
        //子问题：盗取第n个房间时，最大金额
        //f(i,j)=nums[i-1]+max(f(i,j-2),f(i,j-3)); j>3
        //至少隔一个房间，所以是j-2,最多连续隔两个房间j-3，如果更多，比如2 111 2，选择中间的1可以获取更大的值，它不就是j-2的一种情况
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
        //不使用二维数组，使用两个变量也可以
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