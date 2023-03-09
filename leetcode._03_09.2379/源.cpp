class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = k, tmp = 0;
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
                tmp++;
        }
        int result = blocks.size();
        if (tmp >= 0)
            result = min(result, tmp);
        for (int i = 0; r < blocks.size(); i++, r++)
        {
            if (blocks[r] == 'W' && blocks[i] == 'B')
                tmp += 1;
            else if (blocks[r] == 'B' && blocks[i] == 'W')
                tmp -= 1;
            if (tmp >= 0)
                result = min(result, tmp);
        }
        return result;
    }
};