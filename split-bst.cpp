// Given a Binary Search Tree (BST) with root node root, and a target value V, split the tree into two subtrees where one subtree has nodes that are all smaller or equal to the target value, while the other subtree has all nodes that are greater than the target value.  It's not necessarily the case that the tree contains a node with value V.

// Additionally, most of the structure of the original tree should remain.  Formally, for any child C with parent P in the original tree, if they are both in the same subtree after the split, then node C should still have the parent P.

// You should output the root TreeNode of both subtrees after splitting, in any order.

// Example 1:

// Input: root = [4,2,6,1,3,5,7], V = 2
// Output: [[2,1],[4,3,6,null,null,5,7]]
// Explanation:
// Note that root, output[0], and output[1] are TreeNode objects, not arrays.

// The given tree [4,2,6,1,3,5,7] is represented by the following diagram:

//           4
//         /   \
//       2      6
//      / \    / \
//     1   3  5   7

// while the diagrams for the outputs are:

//           4
//         /   \
//       3      6      and    2
//             / \           /
//            5   7         1
// Note:

// The size of the BST will not exceed 50.
// The BST is always valid and each node's value is different.

Let res[0] be tree less than or equal to V, res[1] be tree greater than V.

Detailed explanation: First of all, we can see that the given root is always there in the answer (either in the bigger subtree or in the smaller subtree). After that, if root->val > V, there is a chance that there is some subtree within the subtree root->left which maybe greater than V and that subtree needs to be attached to root->left. Now, we see that this problem of finding "subtree in root->left which is greater than V" is the same as the current problem of splitting root. So we can recurse on left and get the required results. One thing to worry about is, what if there is no subtree in root->left that is greater than V? This case is handled automatically by the base case.
Similar argument applies for the case root->val <= V.

vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode *> res(2, NULL);
        if(root == NULL) return res;
        
        if(root->val > V){
            res[1] = root;
            auto res1 = splitBST(root->left, V);
            root->left = res1[1];
            res[0]=res1[0];
        }else{
            res[0] = root;
            auto res1 = splitBST(root->right, V);
            root->right = res1[0];
            res[1] = res1[1];
        }
        
        return res;
    }