class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> us(deadends.begin(), deadends.end());
        if (us.find("0000") != us.end())
            return -1;
        if (target == "0000")
            return 0;
        unordered_set<string> use;//已使用过不在使用
        use.insert("0000");

        queue<string> q;
        q.push("0000");
        int count = 1;
        while (!q.empty())
        {
            int qSize = q.size();
            while (qSize--)
            {
                string& s = q.front();
                for (int i = 0; i < target.size(); i++)
                {
                    string newS1 = s, newS2 = s;
                    if (s[i] == '9')
                        newS1[i] = '0';
                    else
                        newS1[i] += 1;

                    if (s[i] == '0')
                        newS2[i] = '9';
                    else
                        newS2[i] -= 1;
                    if (us.find(newS1) == us.end())
                    {
                        if (newS1 == target)
                            return count;
                        if (use.find(newS1) == use.end())
                        {
                            q.push(newS1);
                            use.insert(newS1);
                        }
                    }
                    if (us.find(newS2) == us.end())
                    {
                        if (newS2 == target)
                            return count;
                        if (use.find(newS2) == use.end())
                        {
                            q.push(newS2);
                            use.insert(newS2);
                        }
                    }
                }
                q.pop();
            }
            count++;
        }
        return -1;
    }
};