class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0, right = rotateArray.size() - 1;
        int mid = 0;
        //說明沒有旋轉
        if (rotateArray[0] < rotateArray[right])
            return rotateArray[0];
        //旋转后前部分递增元素（345）大于后部分递增元素（12）
        while (left < right) {
            mid = (left + right) >> 1;

            if (right - left == 1) {
                mid = right;
                break;
            }

            if (rotateArray[left] == rotateArray[mid] &&
                rotateArray[mid] == rotateArray[right]) {
                //不确定是前部分还是后部分
                int result = rotateArray[left];
                for (int i = left; i < right; i++) {
                    if (result > rotateArray[i])
                        result = rotateArray[i];
                }
                return result;
            }

            if (rotateArray[left] <= rotateArray[mid]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};
