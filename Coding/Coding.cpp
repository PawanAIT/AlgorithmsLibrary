class Solution {
public:
	vector<vector<int>> ans;
	vector<int>temp;
	void solve(TreeNode* root, int sum) {
		if (root == NULL)
			return;
		sum -= root->val;
		temp.push_back(root->val);
		if (sum == 0 && !(root->left) && !(root->right)) {
			ans.push_back(temp);
		}
		solve(root->left, sum);
		solve(root->right, sum);
		temp.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		solve(root, sum);
		return ans;
	}
};