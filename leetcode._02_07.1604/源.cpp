class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> m;
        int n = keyName.size();
        for (int i = 0; i < n; i++)
        {
            int hour = (keyTime[i][0] - '0') * 10 + keyTime[i][1] - '0';
            int minute = (keyTime[i][3] - '0') * 10 + keyTime[i][4] - '0';
            m[keyName[i]].push_back(hour * 60 + minute);
        }
        vector<string> ans;
        for (pair<string, vector<int>> pr : m)
        {
            sort(pr.second.begin(), pr.second.end());
            if (pr.second.size() < 3)
                break;
            int i = 0, j = 2;
            while (j < pr.second.size())
            {
                if (pr.second[j] - pr.second[i] <= 60)
                {
                    ans.push_back(pr.first);
                    break;
                }
                i++; j++;
            }
            cout << 1;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};