class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (char ch : target)
        {
            m1[ch]++;
        }
        for (char ch : s)
        {
            if (m1.find(ch) != m1.end())
            {
                m2[ch]++;
            }
        }
        int ans = 100;
        for (auto ch : target)
        {
            ans = min(ans, m2[ch] / m1[ch]);
        }
        return ans;
    }
};