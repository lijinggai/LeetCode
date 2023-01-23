class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int count = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (count < k)
                    pq.push(matrix[i][j]);
                else if (pq.top() > matrix[i][j])
                {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
                count++;
            }
        }
        return pq.top();
    }
};