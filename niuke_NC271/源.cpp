#include <vector>
class Solution {
public:
    bool Recursion(vector<int>& v, int left, int right)
    {
        if ((right - left) < 2)
            return true;
        int root = v[right - 1];
        int mid = left;
        for (; mid < right - 1; mid++)
        {
            if (v[mid] > root)
                break;
        }
        for (int i = mid; i < right - 1; i++)
        {
            if (v[i] < root)
                return false;
        }
        return Recursion(v, left, mid) && Recursion(v, mid, right - 1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
        return Recursion(sequence, 0, sequence.size());
    }
};