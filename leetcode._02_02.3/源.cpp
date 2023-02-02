class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0, left = 0;
        unordered_set<char> us;
        for (int i = 0; i < n; i++)
        {
            while (us.find(s[i]) != us.end())
            {
                us.erase(s[left]);
                left++;
            }
            us.insert(s[i]);
            ans = max(i - left + 1, ans);
        }
        return ans;
    }
};