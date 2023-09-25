class Solution {
    int DFS(int n)
    {
        if (n == 1)
            return 0;
        if (m.find(n) != m.end())
            return m.find(n)->second;
        int res = 0;

        if (n % 2 == 0)
            res += DFS(n / 2) + 1;
        else
            res += min(DFS(n / 2), DFS(n / 2 + 1)) + 2;

        m[n] = res;
        return res;
    }
public:
    int integerReplacement(int n) {
        return DFS(n);
    }
    unordered_map<int, int> m;
};
