class Solution {
private:
    void BFS(int& count, vector<int>& v, const int n, int row, unordered_set<int>& cmpA, unordered_set<int>& cmpS)
    {
        //�������һ��
        if (row == n)
        {
            count++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0 && cmpA.find(row + i) == cmpA.end() && cmpS.find(row - i) == cmpS.end())
            {
                cmpA.insert(row + i);//ͬһб����ӻ������ֵ��ͬ
                cmpS.insert(row - i);
                v[i] = 1;//����ĳһ�в���ʹ�ã�
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
        vector<int> v(n, 0);//��Щ�в���ʹ��
        int row = 0;//��ǰ��
        unordered_set<int> cmpA;
        unordered_set<int> cmpS;
        int count = 0;
        BFS(count, v, n, row, cmpA, cmpS);
        return count;
    }
};