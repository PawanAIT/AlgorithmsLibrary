
class Solution {
public:
	int d = 0;
	int ans(TreeNode* root) {
		if (root == NULL)
			return 0;
		int l = ans(root->left);
		int r = ans(root->right);
		d = max(d, l + r);
		return 1 + max(l, r);
	}
	int diameterOfBinaryTree(TreeNode* root) {
		d = 0;
		ans(root);
		return d;
	}
};