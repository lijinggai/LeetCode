class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int pos = 0;
        unordered_map<string, int> us;
        for (string& s : strs) {
            vector<int> tmp(26);
            for (int i = 0; i < s.size(); i++)
                tmp[s[i] - 'a']++;

            string stmp = "";
            for (int i = 0; i < 26; i++)
            {
                while (tmp[i]) {
                    stmp += (i + 'a');
                    //cout<<stmp<<endl;
                    tmp[i]--;
                }
            }

            auto pr = us.find(stmp);
            if (pr == us.end()) {
                vector<string> vs;
                vs.push_back(s);
                ans.push_back(vs);
                us[stmp] = pos++;
            }
            else {
                ans[pr->second].push_back(s);
            }
        }
        return ans;
    }
};