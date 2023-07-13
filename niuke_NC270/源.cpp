#include <string>
class Solution {
private:
    static bool cmp(int x, int y)
    {
        string sx = to_string(x);
        string sy = to_string(y);
        string xy = sx;
        xy += sy;
        string yx = sy;
        yx += sx;
        return xy < yx;
    }
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string result;
        for (int& s : numbers)
        {
            result += to_string(s);
        }
        return result;
    }
};