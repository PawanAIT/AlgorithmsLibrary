class Solution {
    vector<int> ans;
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* root, int level){
        if(root == NULL){
            return;
        }
        if(ans.size() == level){
            ans.push_back(root -> val);
        }
        dfs(root -> right, level + 1);
        dfs(root -> left , level + 1);
    }
};