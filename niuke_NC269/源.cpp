class Solution {
public:
    string ReverseSentence(string str) {
        if (str == "")
            return "";
        stack<string> st;
        string res;
        //使用栈结构
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ' || i == str.size() - 1)
            {
                if (i == str.size() - 1)
                    res += str[i];
                st.push(res);
                res.clear();
            }
            else {
                res += str[i];
            }
        }
        while (!st.empty())
        {
            res += st.top();
            res += ' ';
            st.pop();
        }
        res.pop_back();
        return res;
    }
};