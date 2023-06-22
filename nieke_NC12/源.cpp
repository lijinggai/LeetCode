/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
class Solution {
private:
    TreeNode* Recursion(const vector<int>& pre, int front_pre, int back_pre,
        const vector<int>& vin, int front_vin, int back_vin) {
        if (back_pre <= front_pre)
            return nullptr;
        TreeNode* cur = new TreeNode(pre[front_pre]);
        int target, count = 0;
        for (int i = front_vin; i < back_vin; i++) {
            if (vin[i] == pre[front_pre]) {
                target = i;
                break;
            }
            count++;
        }
        cur->left = Recursion(pre, front_pre + 1, front_pre + 1 + count, vin, front_vin,
            target);
        cur->right = Recursion(pre, front_pre + 1 + count, back_pre, vin, target + 1,
            back_vin);
        return cur;

    }
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty())
            return nullptr;
        return Recursion(pre, 0, pre.size(), vin, 0, vin.size());
    }
};