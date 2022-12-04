class Solution {
public:
    int halfQuestions(vector<int>& questions) {
        int n = questions.size() / 2;
        unordered_map<int, int> m;
        for (auto e : questions)
        {
            m[e]++;
        }
        vector<int> v;
        for (auto e : m)
        {
            v.push_back(e.second);
        }
        sort(v.begin(), v.end(), greater());
        int ret = 0;
        for (auto e : v)
        {
            if (n <= 0)
                return ret;
            n -= e;
            ret++;
        }
        return ret;
    }
};