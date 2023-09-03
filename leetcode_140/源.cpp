class Solution {
    void DFS(vector<string>& res, string& stmp, unordered_map<int, vector<string>>& mp, int cur, const int n)
    {
        if (cur == n)
        {
            stmp.pop_back();//删除" "
            res.push_back(stmp);
            stmp += " ";//增加" ",不是后续删除会越界
            return;
        }
        auto it = mp.find(cur);
        if (it == mp.end())
            return;

        //遍历数组的元素
        for (int i = 0; i < it->second.size(); i++)
        {
            int size = it->second[i].size();

            stmp += it->second[i];
            stmp += " ";

            //使回溯，cur=cur+插入子串的长度
            DFS(res, stmp, mp, cur + size, n);


            for (int j = 0; j < size + 1; j++)
            {
                stmp.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<int, vector<string>> mp;//使用开始下标为Key值，数组保存子串
        unordered_set<string> st(wordDict.begin(), wordDict.end());//字典集转化为哈希表查找效率高
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                //子串
                string sub = s.substr(i, j - i + 1);
                if (st.find(sub) != st.end())
                {
                    //保存可以在字典集找到的子串
                    auto it = mp.find(i);
                    if (it == mp.end()) {//还未插入
                        vector<string> v;
                        v.push_back(sub);
                        mp[i] = v;
                    }
                    else {
                        it->second.push_back(sub);
                    }
                }
            }
        }

        vector<string> res;
        string stmp;
        DFS(res, stmp, mp, 0, n);

        return res;
    }
};