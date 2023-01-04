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
                //ջһֱ����ֱ��']'
                while (st.top() != '[')
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();//ɾ����[��
                int tem = 0, i = 1;
                //���㱶�������ܲ���һλ��
                while (!st.empty() && st.top() >= '0' && st.top() <= '9')
                {
                    cout << st.top();
                    tem += (st.top() - '0') * i;
                    i *= 10;
                    st.pop();//ɾ������
                }
                string tems(ans);
                //׷�ӱ������ַ���
                while (tem - 1)
                {
                    ans += tems;
                    tem--;
                }
                //���ַ���������ջ
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