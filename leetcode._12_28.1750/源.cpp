class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                char temi = s[i], temj = s[j];
                while (i < j && temi == s[i])
                    i++;
                while (i <= j && temj == s[j])
                    j--;
            }
            else
                break;

        }
        return j - i + 1;
    }
};