#include <vector>
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (k == 0)
            return result;
        priority_queue<int, vector<int>, less<int>> q;
        //使用优先级队列来处理topK问题
        for (int i = 0; i < input.size(); i++)
        {
            if (i < k)
            {
                q.push(input[i]);
            }
            else
            {
                if (q.top() > input[i])
                {
                    q.pop();
                    q.push(input[i]);
                }
            }
        }
        while (k--)
        {
            result.push_back(q.top());
            q.pop();
        }
        return result;
    }
};