class BSTIterator {
    private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root = root -> left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
          TreeNode* temp = st.top(); st.pop();
            int val = temp -> val;
            if(temp -> right){
                temp = temp -> right;
                st.push(temp);
                temp = temp -> left;
                 while(temp){
                    st.push(temp);
                    temp = temp -> left;
                }
            }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return st.empty() == false;
    }
};