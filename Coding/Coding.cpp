#include "bits/stdc++.h"
#pragma warning(disable:4996)

using namespace std;

class BinaryTree {
private:
	int val;
	BinaryTree* left;
	BinaryTree* right;
public:
	BinaryTree* insert(BinaryTree* root, int data) {
		if (root == NULL) {
			BinaryTree* x = new BinaryTree();
			x->val = data;
			return x;
		}
		if (root->val > data) {
			 root->left = insert(root->left, data);
		}
		else {
			 root->right = insert(root->right, data);
		}
		return root;
	}

	void inorder(BinaryTree* root) {
		if (root == NULL)
			return;
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
};

int main() {
	BinaryTree b, *x = NULL;
	x = b.insert(x ,5);
	b.insert(x ,12);
	b.insert(x ,56);
	b.insert(x ,7);
	b.insert(x ,0);

	b.inorder(x);

	return 0;
}
