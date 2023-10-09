class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                    q.push(make_pair(i, j));
            }
        }
        vector<vector<int>> dire{ {0,-1},{0,1},{-1,0},{1,0} };
        int curNum = 1;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto tmp = q.front();
                for (int i = 0; i < 4; i++)
                {
                    if (tmp.first + dire[i][0] >= 0 && tmp.first + dire[i][0] < m && tmp.second + dire[i][1] >= 0 && tmp.second + dire[i][1] < n) {
                        if (mat[tmp.first + dire[i][0]][tmp.second + dire[i][1]] != 0)
                        {
                            q.push(make_pair(tmp.first + dire[i][0], tmp.second + dire[i][1]));
                            mat[tmp.first + dire[i][0]][tmp.second + dire[i][1]] = 0;
                            res[tmp.first + dire[i][0]][tmp.second + dire[i][1]] = curNum;
                        }
                    }
                }
                q.pop();
            }
            curNum++;
        }
        return res;
    }
};