class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //注意rowINdex是可以从0开始
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        int i = 0;
        while (i < rowIndex)
        {
            res[i + 1] = 1;
            for (int j = i; j >= 1; j--)
            {
                res[j] = res[j] + res[j - 1];
            }
            i++;
        }
        return res;
    }
};