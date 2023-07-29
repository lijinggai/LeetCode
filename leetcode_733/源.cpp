vector<vector<int>> direction{ {-1,0},{1,0},{0,-1},{0,1} };
class Solution {
public:
    void DFS(vector<vector<int>>& image, int sr, int sc, int& newC, int& oldC)
    {
        //不是旧颜色返回
        if (image[sr][sc] != oldC)
            return;
        image[sr][sc] = newC;
        //计算上下左右
        for (int i = 0; i < direction.size(); i++)
        {
            //一定注意要用临时值去修改；
            int tr = sr, tc = sc;
            if (direction[i][0] != 0)
            {
                tr += direction[i][0];
                if (tr < 0 || tr >= image.size())
                    continue;
            }
            if (direction[i][1] != 0)
            {
                tc += direction[i][1];
                if (tc < 0 || tc >= image[0].size())
                    continue;
            }
            DFS(image, tr, tc, newC, oldC);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldC = image[sr][sc];
        if (color != oldC)
            DFS(image, sr, sc, color, oldC);
        return image;
    }
};