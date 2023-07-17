#include <vector>
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        int total = 0, front = 1, back = 1;
        while (back <= sum) {
            if (total < sum) {
                total += back++;
            }
            else if (total > sum) {
                total -= front;
                front++;
            }
            else {
                //�����ģ�������һ��Ԫ��
                if (back - front > 1) {
                    vector<int> t;
                    for (int j = front; j <= back - 1; j++) {
                        t.push_back(j);
                    }
                    result.push_back(t);
                    total += back++;
                }
            }
        }
        return result;
    }
};