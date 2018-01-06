Node *head = NULL;
Node *p = NULL;
void bsttodll(Node *root){
	if(root == NULL)
		return ;
	bsttodll(root -> left);
	if(p == NULL)
		head = root;
	root -> left = p;
	if(p != NULL)
		p ->right = root;
	
	p = root;
	bsttodll(root -> right);
}
