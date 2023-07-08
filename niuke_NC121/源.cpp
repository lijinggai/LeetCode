#include <cstddef>
#include <unordered_map>
#include <vector>
#include <vector>
class Solution {
private:
    void Swap(string& str, int i, int j)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
    // bool Find(vector<string>& res,string& tmp)
    // {
    //     for(auto e : res)
    //     {
    //         if(tmp==e)
    //             return true;
    //     }
    //     return false;
    // }
    void DFS(string& str, int num, unordered_set<string>& res)
    {
        if (num == str.size())
        {
            // if(!Find(res,tmp))
            //     res.push_back(tmp);
            res.insert(str);
            return;
        }
        for (int i = num; i < str.size(); i++)
        {
            Swap(str, num, i);
            DFS(str, num + 1, res);
            Swap(str, i, num);
        }
    }
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        unordered_set<string> s;
        DFS(str, 0, s);
        for (auto e : s)
        {
            result.push_back(e);
        }
        return result;
    }
};