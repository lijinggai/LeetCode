class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0, n = secret.size();
        unordered_map<char, int> m;
        unordered_map<char, int> m2;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
            {
                m[secret[i]]++;
                m2[guess[i]]++;
            }
        }
        for (const pair<char, int>& p : m2)
        {
            if (m.find(p.first) != m.end())
            {
                cows += min(m[p.first], p.second);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};