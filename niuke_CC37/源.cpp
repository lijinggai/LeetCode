/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include <vector>
class Solution {
private:
	void RecursionDFS(vector<vector<int>>& vv, vector<int>& v, TreeNode* root, int& target, int num)
	{
		if (root == nullptr)
			return;

		v.push_back(root->val);
		num += root->val;
		if (root->left == nullptr && root->right == nullptr && num == target)
			vv.push_back(v);
		RecursionDFS(vv, v, root->left, target, num);
		RecursionDFS(vv, v, root->right, target, num);
		v.pop_back();
	}
public:
	vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> vv;
		vector<int> v;
		int num = 0;
		RecursionDFS(vv, v, root, expectNumber, num);
		return vv;
	}
};