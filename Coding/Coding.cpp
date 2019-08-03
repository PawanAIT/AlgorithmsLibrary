#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	Node* findnext(Node* s) {
		Node* p = s->next;
		while (p) {
			if (p->left) return p->left;
			if (p->right) return p->right;
			p = p->next;
		}
		return NULL;
	}
	Node* connect(Node* root) {
		Node* p = root;
		while (p) {
			Node* q = p;
			while (q) {
				if (q->left) {
					if (q->right) {
						q->left->next = q->right;
					}
					else {
						q->left->next = findnext(q);
					}
				}
				if (q->right) {
					q->right->next = findnext(q);
				}

				q = q->next;
			}
			if (p->left)
				p = p->left;
			else if (p->right)
				p = p->right;
			else p = findnext(p);
		}
	}
};
