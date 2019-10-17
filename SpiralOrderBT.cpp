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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL){
            return ans;
        }
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            vector<int> temp;
            while(!s1.empty())
            {
                TreeNode* node = s1.top();s1.pop();
                temp.push_back(node -> val);
                if(node -> left)
                    s2.push(node -> left);
                if(node -> right)
                    s2.push(node -> right);
            }
            if(temp.size())
                ans.push_back(temp);
            
            temp.clear();
            while(!s2.empty()){
                 TreeNode* node = s2.top();s2.pop();
                temp.push_back(node -> val);
                
                if(node -> right)
                    s1.push(node -> right);
                if(node -> left)
                    s1.push(node -> left);
            }
            if(temp.size())
                ans.push_back(temp);
            
            temp.clear();
        }
        return ans;
    }
};