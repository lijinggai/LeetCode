class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<char> st;
        for (char ch : s)
        {
            if (ch != ']')
                st.push(ch);
            else
            {
                //栈一直插入直到']'
                while (st.top() != '[')
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();//删除‘[’
                int tem = 0, i = 1;
                //计算倍数，可能不是一位数
                while (!st.empty() && st.top() >= '0' && st.top() <= '9')
                {
                    cout << st.top();
                    tem += (st.top() - '0') * i;
                    i *= 10;
                    st.pop();//删除数字
                }
                string tems(ans);
                //追加倍数个字符串
                while (tem - 1)
                {
                    ans += tems;
                    tem--;
                }
                //把字符串拷贝回栈
                while (!ans.empty())
                {
                    st.push(ans.back());
                    ans.pop_back();
                }
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};