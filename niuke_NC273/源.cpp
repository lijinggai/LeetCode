/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
private:
    bool cmp(TreeNode* root1, TreeNode* root2) {
        if (root2 == nullptr)
            return true;
        if (root1 == nullptr || root1->val != root2->val)
            return false;
        return (cmp(root1->left, root2->left) && cmp(root1->right, root2->right));
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        if (pRoot1->val == pRoot2->val) {
            if (cmp(pRoot1, pRoot2))
                return true;
        }
        return(HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
    }
};
