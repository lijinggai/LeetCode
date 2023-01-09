class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int arr[3] = { a,b,c };
        sort(arr, arr + 3);
        if (arr[0] + arr[1] <= arr[2])
            return arr[0] + arr[1];
        else
            return (arr[2] + arr[1] + arr[0]) / 2;
    }
};