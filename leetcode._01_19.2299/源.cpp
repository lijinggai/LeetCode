class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8)
            return false;
        unordered_set<char> s{ '!','@','#','$','%','^','&','*','(',')','-','+' };
        int* cmp = new int[4] {0};
        for (int i = 0; i < password.size(); i++)
        {
            if (i != 0 && password[i - 1] == password[i])
                return false;
            if (isupper(password[i]))
                cmp[0] = 1;
            if (islower(password[i]))
                cmp[1] = 1;
            if (isdigit(password[i]))
                cmp[3] = 1;
            if (s.find(password[i]) != s.end())
                cmp[2] = 1;
        }
        return cmp[0] == 1 && cmp[1] == 1 && cmp[2] == 1 && cmp[3] == 1;
    }
};