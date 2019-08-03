Node* p = NULL;
bool f = true;
void check(Node* root) {
	if (root == NULL)
		return;
	check(root->left);
	if (p != NULL && p->data > root->data)
		f = false;
	p = root;
	check(root->right);
}
bool isBST(Node* root) {
	f = true;
	p = NULL;
	check(root);
	return f;
}