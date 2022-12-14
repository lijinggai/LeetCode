class Solution {
public:
    void backtrack(vector<string>& vs, string& s, int left, int right, int n)
    {
        //��������
        if (s.size() == 2 * n)
        {
            vs.push_back(s);
            return;
        }
        //���������С��n���
        if (left < n)
        {
            s.push_back('(');
            backtrack(vs, s, left + 1, right, n);
            //�ٴλص�����,�ᰴ��������ִ������
            s.pop_back();
        }
        if (right < left)
        {
            s.push_back(')');
            backtrack(vs, s, left, right + 1, n);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        string s;
        backtrack(vs, s, 0, 0, n);
        return vs;
    }
};