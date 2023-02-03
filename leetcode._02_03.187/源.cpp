class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int len = s.size(), l = 0;
        unordered_map<string, int> res;
        for (l = 0; l <= len - 10; l++)
        {
            string tmp = s.substr(l, 10);
            unordered_map<string, int>::iterator fd = res.find(tmp);
            if (fd == res.end())
            {
                res[tmp] = 1;
            }
            else
            {
                if (fd->second == 1)
                {
                    ans.push_back(tmp);
                    fd->second = 0;
                }

            }
        }
        return ans;
    }
};