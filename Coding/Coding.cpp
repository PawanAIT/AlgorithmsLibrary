#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	vector<int> ans;
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		dfs(root, target, K);
		return ans;
	}
	void addnodes(TreeNode* root, int k) {
		if (root == NULL || k < 0)
			return;
		if (k == 0)
			ans.push_back(root->val);
		addnodes(root->left, k - 1);
		addnodes(root->right, k - 1);
	}

	int dfs(TreeNode* root, TreeNode* target, int K) {
		if (root == NULL)
			return -1;
		if (root == target) {
			addnodes(root, K);
			return 1;
		}
		int L = dfs(root->left, target, K);
		int R = dfs(root->right, target, K);
		if (L != -1) {
			if (L == K) {
				ans.push_back(root->val);
			}
			addnodes(root->right, K - L - 1);
			return L + 1;
		}
		if (R != -1) {
			if (R == K) {
				ans.push_back(root->val);
			}
			addnodes(root->left, K - R - 1);
			return R + 1;
		}
		return -1;
	}
};