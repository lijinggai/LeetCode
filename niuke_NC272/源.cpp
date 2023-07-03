class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushV.size()) {
            //��������
            st.push(pushV[i++]);
            //�ж�ջ��popv�Ƿ����
            while (!st.empty() && st.top() == popV[j]) {
                //popv++,ջ����
                j++;
                st.pop();
            }
        }
        if (j == popV.size())
            return true;
        else
            return false;
    }
};