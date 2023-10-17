class Solution {
public:
    int reverse(int x) {
        int flag = 0;
        if (x == -2147483648)
            return 0;
        if (x < INT_MIN || x > INT_MAX)
            return 0;
        if (x < 0)
        {
            flag = 1;
            x = -x;
        }
        string s;
        while (x)
        {
            if (x % 10 == 0 && s.size() > 0)
                s += x % 10;
            if (x % 10 > 0)
                s += x % 10;
            x /= 10;
        }
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (ans + s[i] / 10 < INT_MIN / 10 || ans + s[i] / 10 > INT_MAX / 10)
                return 0;
            ans = ans * 10 + s[i];
        }
        return flag == 0 ? ans : -ans;
    }
};