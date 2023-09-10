class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n + 1, 0);
        //ƽ������n�ͽ���
        for (int i = 1; i * i <= n; i++)
        {
            int square = i * i;//��ǰƽ��
            for (int j = square; j < n + 1; j++)
            {
                if (i == 1)//������ʼ��
                    res[j] = j;
                else
                    res[j] = min(res[j], res[j - square] + 1);
            }
        }
        return res[n];

    }
};