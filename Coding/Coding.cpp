#include "bits/stdc++.h"
#pragma warning(disable:4996)

using namespace std;

class Node {
private:
	int data;
	Node* left;
	Node* right;
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			Node* x = new Node();
			x->data = data;
			return x;
		}
		if (root->data > data) {
			 root->left = insert(root->left, data);
		}
		else {
			 root->right = insert(root->right, data);
		}
		return root;
	}

	void inorder(Node* root) {
		if (root == NULL)
			return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	int sumOfLeafNodes(Node* root) {
		if (root == NULL) {
			return 0;
		}
		if (root->left == NULL and root->right == NULL)
			return root->data;

		int leftSum = sumOfLeafNodes(root->left);
		int rightSum = sumOfLeafNodes(root->right);
		return leftSum + rightSum;
	}

	int Morris(Node* root) {
		Node* cur = root;
		while (cur != NULL) {
			if (cur->left == NULL) {
				cout << cur->data << " ";
				cur = cur->right;
			}
			else {
				Node* p = cur->left;
				while (p->right != NULL and p->right != cur)
					p = p->right;
				if (p->right == cur) {
					p->right = NULL;
					cout << cur->data << " "; // Inorder
					cur = cur->right;
				}
				else {
					//cout << cur -> data << " "; // Preorder
					p->right = cur;
					cur = cur->left;
				}
			}
		}
	}

	Node* SetPredAndDetachLink(Node* cur) {
		Node* p = cur->left;
		while (p->right != NULL and p->right != cur) {
			p = p->right;
		}
		if (p ->right != cur) {
			p->right = cur;
			return p;
		}
		else {
			p->right = NULL;
			return cur;
		}
	}

	void MorrisTraversal(Node* cur) {
		while (cur != NULL) {
			if (cur->left == NULL) {
				cout << cur->data << " ";
				cur = cur->right;
			}
			else {
				Node* temp = SetPredAndDetachLink(cur);
				if (temp == cur) {
					cout << cur->data << " ";
					cur = cur->right;
				}
				else {
					cur = cur->left;
				}
			}
		}
	}
};

int main() {
	Node b, *x = NULL;
	x = b.insert(x ,7);
	b.insert(x ,4);
	b.insert(x ,10);
	b.insert(x ,5);
	b.insert(x ,6);
	b.insert(x ,2);
	b.insert(x ,3);
	b.insert(x ,1);
	b.insert(x ,8);
	b.insert(x ,9);
	b.insert(x ,11);

	//b.inorder(x);

	b.MorrisTraversal(x);
	cout << endl;
	b.MorrisTraversal(x);

	return 0;
}
