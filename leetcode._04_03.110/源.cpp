/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool _isBalanced(struct TreeNode* root, int* pi) {
    if (root == NULL)
        return true;
    //ºóÐò
    //ÏÈÅÐ¶Ï×ó×ÓÊ÷£¬ÔÙÅÐ¶ÏÓÒ×ÓÊ÷
    int leftsize = 0;
    if (_isBalanced(root->left, &leftsize) == false)
        return false;

    int rightsize = 0;
    if (_isBalanced(root->right, &rightsize) == false)
        return false;

    *pi = fmax(leftsize, rightsize) + 1;

    return abs(leftsize - rightsize) < 2;
}

bool isBalanced(struct TreeNode* root) {
    int i = 0;
    return _isBalanced(root, &i);
}