class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> m;
        int answer = 0, n = s.size();
        for (int i = 0; i < n - minSize + 1; i++)
        {
            unordered_set<char> st;
            string temporary;
            for (int j = i; j < min(n, i + maxSize); j++)
            {
                st.insert(s[j]);
                if (st.size() > maxLetters)
                    break;
                temporary += s[j];
                if (j - i + 1 >= minSize)
                {
                    m[temporary]++;
                    answer = max(answer, m[temporary]);
                }
            }
        }
        return answer;
    }
};
