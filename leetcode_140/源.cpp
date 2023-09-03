class Solution {
    void DFS(vector<string>& res, string& stmp, unordered_map<int, vector<string>>& mp, int cur, const int n)
    {
        if (cur == n)
        {
            stmp.pop_back();//ɾ��" "
            res.push_back(stmp);
            stmp += " ";//����" ",���Ǻ���ɾ����Խ��
            return;
        }
        auto it = mp.find(cur);
        if (it == mp.end())
            return;

        //���������Ԫ��
        for (int i = 0; i < it->second.size(); i++)
        {
            int size = it->second[i].size();

            stmp += it->second[i];
            stmp += " ";

            //ʹ���ݣ�cur=cur+�����Ӵ��ĳ���
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
        unordered_map<int, vector<string>> mp;//ʹ�ÿ�ʼ�±�ΪKeyֵ�����鱣���Ӵ�
        unordered_set<string> st(wordDict.begin(), wordDict.end());//�ֵ伯ת��Ϊ��ϣ�����Ч�ʸ�
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                //�Ӵ�
                string sub = s.substr(i, j - i + 1);
                if (st.find(sub) != st.end())
                {
                    //����������ֵ伯�ҵ����Ӵ�
                    auto it = mp.find(i);
                    if (it == mp.end()) {//��δ����
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