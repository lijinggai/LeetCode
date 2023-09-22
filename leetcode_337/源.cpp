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
    int _rob(TreeNode* root, unordered_map<TreeNode*, int>& memory)
    {
        if (root == nullptr)
            return 0;
        //如果存在
        if (memory.find(root) != memory.end())
            return memory.find(root)->second;
        int res = root->val;
        if (root->left)
            res += _rob(root->left->left, memory) + _rob(root->left->right, memory);
        if (root->right)
            res += _rob(root->right->left, memory) + _rob(root->right->right, memory);

        int t = max(res, _rob(root->left, memory) + _rob(root->right, memory));
        //保存当前最大值   
        memory[root] = t;
        return t;
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memory;

        return _rob(root, memory);
    }
};