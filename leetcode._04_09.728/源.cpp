/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize)
{
    int n = right - left + 1;
    int* nums = (int*)malloc(sizeof(int) * n);
    int i = 0;
    while (right + 1 > left)
    {
        nums[i++] = left;
        left++;
    }
    i = 0;
    int j = 0;
    while (i < n)
    {
        int tmp = nums[i];
        while (tmp)
        {
            int b = tmp % 10;
            if (b == 0)
            {
                break;
            }
            if (nums[i] % b != 0)
            {
                break;
            }
            tmp /= 10;
        }
        if (tmp == 0)
        {
            nums[j++] = nums[i];
        }
        i++;
    }
    *returnSize = j;
    return nums;
}