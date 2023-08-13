vector<char> v{ 'A', 'C', 'G', 'T' };
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> us(bank.begin(), bank.end());
        queue<string> q;
        q.push(startGene);
        int count = 0;
        if (us.find(endGene) == us.end())
            return -1;
        while (!q.empty())
        {
            if (us.empty())
                return -1;
            int qSize = q.size();
            while (qSize--)
            {
                string& gene = q.front();
                for (int i = 0; i < gene.size(); i++)
                {
                    string newGene = gene;
                    for (int j = 0; j < v.size(); j++)
                    {
                        newGene[i] = v[j];
                        if (us.find(newGene) != us.end())
                        {
                            if (newGene == endGene)
                            {
                                return count + 1;
                            }
                            //ɾ���ַ�����Ӧ��Ԫ�أ���ֹ�ظ�ʹ��
                            q.push(newGene);
                            us.erase(newGene);
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