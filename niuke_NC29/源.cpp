class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int n = array[0].size();
        int i = 0;
        int j = n - 1;
        //ѡȡ���Ͻǵ�Ԫ��
        while (i < array.size() && j >= 0) {
            if (array[i][j] > target)
            {
                j--;
            }
            else if (array[i][j] < target)
            {
                i++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

/*  */