class Solution {
public:
    int numDecodings(string s) {
        //可分为3种类型
        //当前字符只可以构成一个字母
        //当前字符和前一个字符只可以构成一个字母
        //当前字符可以构成、当前字符和前一个字符可以构成
        // f(i)=f(i-1) 1<=i&&i<=9
        // f(i)=f(i-2) i==20||i=10
        // f(i)=f(i-1)+f(i-2) 11<=i && i<=19 && i<=21 && i<=26
        int n = s.size();
        s = "0" + s;//
        vector<int> res(n + 1, 0);
        res[0] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            if (s[i] - '0' >= 1 && s[i] - '0' <= 9)
                res[i] += res[i - 1];
            int tmp = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (tmp >= 10 && tmp <= 26)
                res[i] += res[i - 2];
        }
        return res[n];
    }
};