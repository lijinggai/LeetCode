class Solution {
public:
    char repeatedCharacter(string s) {
        int* arr = new int[32] {0};
        for (char ch : s)
        {
            if (arr[ch - 'a'] == 0)
                arr[ch - 'a']++;
            else
            {
                return ch;
            }
        }
        return 'a';
    }
};