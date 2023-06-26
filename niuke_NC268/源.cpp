public class Solution {
    public int rectCover(int target) {
        if (target == 1 || target == 0)
            return target;
        int first = 1, second = 1;
        for (int i = 2; i <= target; i++) {
            int t = first + second;
            first = second;
            second = t;
        }
        return second;
    }
}
