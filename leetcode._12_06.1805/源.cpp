class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size(), i = 0;
        unordered_set<string> st;
        while (i < n)
        {
            string s;
            int falg = 0;
            while (i < n && word[i] >= '0' && word[i] <= '9')
            {
                if (s.size() == 0 && word[i] == '0')//³ýÁËÇ°ÖÃ0
                    falg = 1;
                else
                    s.push_back(word[i]);
                i++;
            }
            if (s.size() != 0)
                st.insert(s);
            else
            {
                if (falg == 1 && s.size() == 0)
                {
                    s.push_back('0');
                    st.insert(s);
                }
                i++;
            }

        }
        return st.size();
    }
};