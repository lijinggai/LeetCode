/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            while (size)
            {
                TreeNode* cur = q.front();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);

                //一行的最后一个元素
                if (size == 1)
                    res.push_back(cur->val);
                q.pop();
                size--;
            }
        }
        return res;
    }
};