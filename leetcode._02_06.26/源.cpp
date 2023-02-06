/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool recursion(TreeNode* A, TreeNode* B)
    {
        if (!B)
            return true;
        if (!A)
            return false;
        if (A->val == B->val)
            return recursion(A->left, B->left) && recursion(A->right, B->right);
        else
            return false;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B)
            return false;
        if (A->val == B->val && recursion(A, B))
            return true;
        else
            return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};