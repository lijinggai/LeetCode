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
            //��ǰֵ����С����һ��ֵ
            if (index <= candidates[i])
            {
                t.push_back(candidates[i]);
                //������Ҫ��
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
        int index = candidates[0];//��ֹѡ��ȵ�ǰֵС��
        DFS(res, t, index, total, candidates, target);
        return res;
    }
};