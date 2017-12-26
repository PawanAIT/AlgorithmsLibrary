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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(root == NULL)
            return 0;
        int l = 0 , r = 0;
        l = solve(root -> left);
        r = solve(root -> right);
        if(l < 0) l = 0;
        if(r < 0) r = 0;
        ans = max(ans , l + r + root ->val);
        return root -> val + max(l , r);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
