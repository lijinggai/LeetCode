/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        int index = 1;
        queue<Node*> q;
        q.push(root);
        while (index)
        {
            Node* prev = nullptr;
            for (int i = index; i > 0; i--)
            {
                Node* tmp = q.front();
                if (tmp->right) {
                    q.push(tmp->right);
                    q.push(tmp->left);
                }
                q.pop();
                if (prev == nullptr) {
                    prev = tmp;
                    prev->next = nullptr;
                }
                else {
                    tmp->next = prev;
                    prev = tmp;
                }
            }
            index = q.size();
        }
        return root;
    }
};
