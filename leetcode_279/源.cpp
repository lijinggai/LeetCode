class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n + 1, 0);
        //平方大于n就结束
        for (int i = 1; i * i <= n; i++)
        {
            int square = i * i;//当前平方
            for (int j = square; j < n + 1; j++)
            {
                if (i == 1)//当作初始化
                    res[j] = j;
                else
                    res[j] = min(res[j], res[j - square] + 1);
            }
        }
        return res[n];

    }
};