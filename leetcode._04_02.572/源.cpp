/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q)//是否相等
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
        return false;
    //每个节点都作为自述子树的根跟s比较
    if (isSameTree(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) ||
        isSubtree(root->right, subRoot);
}