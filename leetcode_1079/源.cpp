class Solution {
private:
    void Swap(char& x, char& y)
    {
        if (x != y)
        {
            char t = x;
            x = y;
            y = t;
        }
    }
    void DFS(string& tiles, int cur, unordered_set<string>& res, string& s)
    {
        if (s.size() != 0)
        {
            res.insert(s);
        }
        if (cur == tiles.size())
            return;
        for (int i = cur; i < tiles.size(); i++)
        {
            Swap(tiles[i], tiles[cur]);
            s.push_back(tiles[cur]);
            DFS(tiles, cur + 1, res, s);
            //交换变为原字符串
            Swap(tiles[i], tiles[cur]);
            s.pop_back();
        }
    }
public:
    int numTilePossibilities(string tiles) {
        string s;
        unordered_set<string> res;
        int cur = 0;
        DFS(tiles, cur, res, s);
        return res.size();
    }
};