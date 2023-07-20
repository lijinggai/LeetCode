
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
#include <vector>
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot == nullptr)
            return res;
        queue<TreeNode*> q;
        stack<int> st;
        q.push(pRoot);
        int flag = 0;
        while (!q.empty()) {
            vector<int> v;
            int size = q.size();
            if (flag == 0) {
                while (size--) {
                    TreeNode* cur = q.front();
                    if (cur->left)
                        q.push(cur->left);
                    if (cur->right)
                        q.push(cur->right);

                    v.push_back(cur->val);
                    q.pop();
                    //设置为1，下一次使用栈reverse元素
                    flag = 1;
                }
            }
            else {
                while (size--) {
                    TreeNode* cur = q.front();
                    if (cur->left)
                        q.push(cur->left);
                    if (cur->right)
                        q.push(cur->right);

                    st.push(cur->val);
                    //设置为0,下一次不用逆转
                    q.pop();
                    flag = 0;
                }
                while (!st.empty())
                {
                    v.push_back(st.top());
                    st.pop();
                }
            }
            res.push_back(v);
        }
        return res;
    }

};