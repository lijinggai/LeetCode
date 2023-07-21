class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0, r = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                l++;
            if (s[i] == 'R')
                r++;
            if (l == r)
                count++;
        }
        return count;
    }
};