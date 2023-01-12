class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        map<string, string> m;
        for (vector<string> vs : knowledge)
        {
            m[vs[0]] = vs[1];
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                i++;
                string temporary;
                while (i < s.size() && s[i] != ')')
                {
                    temporary += s[i];
                    i++;
                }
                if (m.find(temporary) != m.end())
                    ans += m[temporary];
                else
                    ans += '?';
            }
            else
                ans += s[i];
        }
        return ans;
    }
};