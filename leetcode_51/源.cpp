class Solution {
private:
    void BFS(vector<vector<string>>& res, vector<int>& v, vector<string>& vs, const int n, int row, unordered_set<int>& cmpA, unordered_set<int>& cmpS)
    {
        //到达最后一行
        if (row == n)
        {
            res.push_back(vs);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0 && cmpA.find(row + i) == cmpA.end() && cmpS.find(row - i) == cmpS.end())
            {
                cmpA.insert(row + i);//同一斜列相加或相减的值相同
                cmpS.insert(row - i);
                vs[row][i] = 'Q';//结果数组
                v[i] = 1;//代表某一列不能使用；
                BFS(res, v, vs, n, row + 1, cmpA, cmpS);
                cmpA.erase(row + i);
                cmpS.erase(row - i);
                vs[row][i] = '.';
                v[i] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;//
        vector<string> vs(n, string(n, '.'));
        vector<int> v(n, 0);//哪些列不能使用
        int row = 0;//当前行
        unordered_set<int> cmpA;
        unordered_set<int> cmpS;
        BFS(res, v, vs, n, row, cmpA, cmpS);
        return res;
    }
};