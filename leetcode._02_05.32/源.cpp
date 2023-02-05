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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root == nullptr)
            return ans;
        q.push(root);
        int flag = 0;
        while (!q.empty())
        {
            int target = q.size();
            vector<int> tmp;
            while (target--)
            {
                tmp.push_back(q.front()->val);
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            if (flag % 2 == 1)
            {
                reverse(tmp.begin(), tmp.end());
                ans.push_back(tmp);

            }
            else
                ans.push_back(tmp);
            flag++;
        }
        return ans;
    }
};