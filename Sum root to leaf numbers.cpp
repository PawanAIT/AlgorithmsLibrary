//https://leetcode.com/problems/sum-root-to-leaf-numbers/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int ans = 0;
	int sumNumbers(TreeNode* root)
	{
		int sum = 0;
		dfs(root, sum);
		return ans;
	}
	void dfs(TreeNode *root, int sum) {
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
			ans += sum * 10 + root ->val;
		dfs(root->left, sum * 10 + root->val);
		dfs(root->right, sum * 10 + root->val);
	}
};