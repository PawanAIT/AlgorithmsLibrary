#include <cstddef>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		vector<int> temp;
		if (root == NULL)
			return ans;
		queue<TreeNode*> Q;
		Q.push(root);
		Q.push(NULL);
		while (!Q.empty()) {
			auto top = Q.front(); Q.pop();
			if (top == NULL) {
				ans.push_back(temp);
				temp.clear();
				if (Q.size() > 0) {
					Q.push(NULL);
				}
			}
			else {
				temp.push_back(top->val);
				if (top->left)
					Q.push(top->left);
				if (top->right)
					Q.push(top->right);
			}
		}
		return ans;
	}
};