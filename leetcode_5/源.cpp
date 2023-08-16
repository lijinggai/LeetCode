class Solution {
private:
    bool Palindrome(string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int maxp = 1;
        int left, right;
        for (int i = 1; i < s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (Palindrome(s, j, i))
                {
                    if (i - j + 1 > maxp)
                    {
                        maxp = i - j + 1;
                        left = j, right = i;
                    }
                }
            }
        }
        string res;
        res.push_back(s[0]);
        if (maxp == 1)
            return res;
        res = s.substr(left, right - left + 1);
        return res;
    }
};