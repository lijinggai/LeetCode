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
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
		if (root == nullptr)
			return result;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int i = q.size();
			while (i--)
			{
				TreeNode* t = q.front();
				result.push_back(t->val);
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
				q.pop();
			}
		}
		return result;
	}
};