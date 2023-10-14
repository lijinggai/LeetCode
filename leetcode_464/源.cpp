class Solution {
    bool DFS(int stat, int sum, int maxChoosableInteger, int desiredTotal)
    {
        if (memo_[stat] == 1)
            return true;
        if (memo_[stat] == 2)
            return false;
        for (int i = 1; i < maxChoosableInteger + 1; i++)
        {
            if (((1 << i) & stat))
                continue;
            if (sum + i >= desiredTotal)
            {
                memo_[stat] = 1;
                return true;
            }
            if (!DFS((1 << i) | stat, sum + i, maxChoosableInteger, desiredTotal))
            {
                memo_[stat] = 1;
                return true;
            }
        }
        memo_[stat] = 2;
        return false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger + 1 == desiredTotal)
            return false;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;

        return DFS(0, 0, maxChoosableInteger, desiredTotal);
    }
private:
    int memo_[1 << 21];
};





