class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushV.size()) {
            //插入数据
            st.push(pushV[i++]);
            //判读栈和popv是否相等
            while (!st.empty() && st.top() == popV[j]) {
                //popv++,栈弹出
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