class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int answer = wall.size(), n = answer;

        unordered_map<int, int> res;
        for (int i = 0; i < n; i++) {
            int m = wall[i].size(), tmp = 0;
            for (int j = 0; j < m; j++) {
                tmp += wall[i][j];
                res[tmp]++;
            }
            res.erase(tmp);
        }

        unordered_map<int, int>::iterator it = res.begin();
        while (it != res.end())
        {
            answer = min(n - it->second, answer);
            it++;
        }
        return answer;
    }
};