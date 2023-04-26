/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int MAX(int x, int y)
{
    return x > y ? x : y;
}
int _longestUnivaluePath(struct TreeNode* root, int* ret)
{
    if (root == NULL)//到一条路线的叶子
        return 0;
    int left = _longestUnivaluePath(root->left, ret);
    int right = _longestUnivaluePath(root->right, ret);//后序遍历
    int left1 = 0, right1 = 0;
    if (root->left && root->left->val == root->val)
    {
        left1 = left + 1;//左子树是否相同
    }
    if (root->right && root->right->val == root->val)
    {
        right1 = right + 1;//右子树是否相同
    }
    *ret = MAX(*ret, left1 + right1);//与ret比较
    return MAX(left1, right1);//
}

int longestUnivaluePath(struct TreeNode* root)
{
    int ret = 0;
    _longestUnivaluePath(root, &ret);
    return ret;
}