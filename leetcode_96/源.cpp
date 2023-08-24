class Solution {
public:
    int numTrees(int n) {
        //卡特兰数：f(i)=f(i-1)*f(0)+f(i-2)*(1)+...+f(1)*f(i-2)+f(0)*f(i-1);
        vector<int> res(n + 1, 0);
        res[0] = 1, res[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            int start = 0, end = i - 1;
            while (start <= (i - 1) / 2)
            {
                //相同只用一次
                if (start == end)
                    res[i] += res[start] * res[end];
                else
                    res[i] += 2 * res[start] * res[end];
                start++; end--;
            }
        }
        return res[n];
    }
};