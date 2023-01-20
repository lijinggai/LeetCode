class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k, 0);
        unordered_map<int, unordered_set<int>> m;
        for (vector<int>& v : logs)
        {
            int id = v[0];
            int operate = v[1];
            m[id].insert(operate);
        }
        for (auto& e : m)
        {
            ans[e.second.size() - 1]++;
        }
        return ans;
    }
};