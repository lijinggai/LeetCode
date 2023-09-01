class Solution {
    void DFS(vector<vector<string>>& ans, vector<string>& t, const vector<vector<bool>>& palind, const string& s, int cur, const int n)
    {
        if (cur == n)
        {
            ans.push_back(t);
            return;
        }

        for (int j = cur; j < n; j++)
        {
            if (palind[cur][j])//ÊÇ»ØÎÄ
            {
                string sub = s.substr(cur, j - cur + 1);
                t.push_back(sub);
                DFS(ans, t, palind, s, j + 1, n);
                t.pop_back();
            }

        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> palind(n, vector<bool>(n, true));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                palind[i][j] = (s[i] == s[j]) && palind[i + 1][j - 1];
            }
        }

        vector<vector<string>> ans;
        vector<string> t;
        DFS(ans, t, palind, s, 0, n);
        return ans;
    }
};