vector<vector<int>> direction{ {-1,0},{1,0},{0,-1},{0,1} };
class Solution {
private:
    void BFS(vector<vector<int>>& grid, queue<pair<int, int>>& q, int& count, int& badO)
    {
        while (!q.empty())
        {
            int qSize = q.size();
            while (qSize--)
            {
                auto& qf = q.front();
                for (int i = 0; i < direction.size(); i++)
                {
                    //�ж������»������ҼӼ�
                    if (direction[i][0] != 0) {
                        //�����Ƿ�Ϸ�
                        if (qf.first + direction[i][0] >= 0 && qf.first + direction[i][0] < grid.size()) {
                            //�Ƿ�Ϊ��������
                            if (grid[qf.first + direction[i][0]][qf.second] == 1)
                            {
                                //��������++
                                grid[qf.first + direction[i][0]][qf.second] = 2;
                                badO++;
                                //��ǰ���õļ������
                                q.push(make_pair(qf.first + direction[i][0], qf.second));
                            }
                        }
                    }
                    else {
                        if (qf.second + direction[i][1] >= 0 && qf.second + direction[i][1] < grid[0].size()) {
                            if (grid[qf.first][qf.second + direction[i][1]] == 1)
                            {
                                //��������++
                                grid[qf.first][qf.second + direction[i][1]] = 2;
                                badO++;
                                //��ǰ���õļ������
                                q.push(make_pair(qf.first, qf.second + direction[i][1]));
                            }
                        }
                    }
                }
                //ɾ����һ��Ԫ��
                q.pop();
            }
            count++;
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totalO = 0,/*�ܹ���oranges*/badO = 0;
        queue<pair<int, int>> q;//BFS
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                    totalO++;
                    badO++;
                }
                else if (grid[i][j] == 1)
                    totalO++;
            }
        }
        if (q.empty() && totalO != 0)
            return -1;
        else if (q.empty() && totalO == 0)
            return 0;
        int count = 0;
        BFS(grid, q, count, badO);
        //cout<<badO<<": "<<count<<endl;
        if (badO != totalO)
            return -1;
        return count - 1;
    }
};