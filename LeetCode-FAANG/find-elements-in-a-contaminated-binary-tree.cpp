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
class FindElements {
	set<int> s;
public:
	FindElements(TreeNode* root) {
		function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int val) {
			if (root == NULL)
				return;
			root->val = val;
			s.insert(val);
			dfs(root->left, 2 * val + 1);
			dfs(root->right, 2 * val + 2);
		};
        dfs(root, 0);
	}

	bool find(int target) {
		return s.find(target) != s.end();
	}
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */