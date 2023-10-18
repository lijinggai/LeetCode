class Solution {
public:
    int maxArea(vector<int>& height) {
        int r = height.size() - 1, l = 0;
        int ans = 0;
        while (l < r)
        {
            int minLine = min(height[l], height[r]);
            ans = max(ans, minLine * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};