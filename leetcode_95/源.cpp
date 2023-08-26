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
    vector<TreeNode*> Recursion(int start, int end)
    {
        if (start > end)
        {
            return { nullptr };
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++)
        {
            //构建左子树的所以可能
            vector<TreeNode*> leftV = Recursion(start, i - 1);
            //构建右子树的所以可能
            vector<TreeNode*> rightV = Recursion(i + 1, end);
            for (auto left : leftV)
            {
                for (auto right : rightV)
                {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = left;
                    cur->right = right;
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return Recursion(1, n);
    }
};