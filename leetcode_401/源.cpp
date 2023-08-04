class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        //在可能值中计算二进制1的个数和给的数做比较
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return ans;
    }
};