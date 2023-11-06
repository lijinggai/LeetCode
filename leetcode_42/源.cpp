class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int minNum = 1, prevNum = 0, ans = 0;
        while (left < right)
        {
            //找到两个比最低水位的值
            while (left < right && height[left] < minNum) {
                left++;
            }
            while (left < right && height[right] < minNum) {
                right--;
            }
            // cout<<left<<" "<<right<<" "<<minNum<<endl;
             //当前最低水位
            minNum = min(height[left], height[right]);
            for (int i = left + 1; i < right; i++) {
                if (height[i] < minNum)
                    ans += minNum - (prevNum >= height[i] ? prevNum : height[i]);
            }
            //下一次最低水位+1
            prevNum = minNum;
            minNum += 1;
            //cout<<ans;
        }
        return ans;
    }
};