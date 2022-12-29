class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> v;
        map<int, int> m;
        for (auto e : nums1)
        {
            m[e] = 1;
        }
        for (auto e : nums2)
        {
            m[e] |= 0X2;
        }
        for (auto e : nums3)
        {
            m[e] |= 0X4;
        }
        for (auto e : m)
        {
            if (e.second & (e.second - 1))
                v.push_back(e.first);
        }
        return v;
    }
};