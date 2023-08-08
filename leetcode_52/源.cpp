class Solution {
private:
    void BFS(int& count, vector<int>& v, const int n, int row, unordered_set<int>& cmpA, unordered_set<int>& cmpS)
    {
        //到达最后一行
        if (row == n)
        {
            count++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0 && cmpA.find(row + i) == cmpA.end() && cmpS.find(row - i) == cmpS.end())
            {
                cmpA.insert(row + i);//同一斜列相加或相减的值相同
                cmpS.insert(row - i);
                v[i] = 1;//代表某一列不能使用；
                BFS(count, v, n, row + 1, cmpA, cmpS);
                cmpA.erase(row + i);
                cmpS.erase(row - i);
                v[i] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<string> vs(n, string(n, '.'));
        vector<int> v(n, 0);//哪些列不能使用
        int row = 0;//当前行
        unordered_set<int> cmpA;
        unordered_set<int> cmpS;
        int count = 0;
        BFS(count, v, n, row, cmpA, cmpS);
        return count;
    }
};