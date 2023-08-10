/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<Node*> q;
        //放入头结点
        q.push(root);
        while (!q.empty())
        {
            int num = q.size();
            vector<int> t;
            while (num--)
            {
                //拿出节点
                auto& node = q.front();
                t.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++)
                {
                    if (node->children[i] != nullptr)
                        q.push(node->children[i]);
                }
                q.pop();
            }
            res.push_back(t);
        }
        return res;
    }
};