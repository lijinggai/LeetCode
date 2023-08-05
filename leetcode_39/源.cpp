class Solution {
private:
    void DFS(vector<vector<int>>& res, vector<int>& t, int index, int total, const vector<int>& candidates, const int& target)
    {
        if (total >= target)
        {
            if (total == target)
                res.push_back(t);
            return;
        }
        for (int i = 0; i < candidates.size(); i++)
        {
            //当前值不能小于上一个值
            if (index <= candidates[i])
            {
                t.push_back(candidates[i]);
                //总量需要加
                index = candidates[i];
                DFS(res, t, index, total + candidates[i], candidates, target);
                t.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> t;
        int total = 0;
        int index = candidates[0];//防止选择比当前值小的
        DFS(res, t, index, total, candidates, target);
        return res;
    }
};