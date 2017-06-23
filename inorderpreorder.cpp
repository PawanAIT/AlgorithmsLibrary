#include <bits/stdc++.h>
using namespace std;
 
struct node
{
	node * left;
	node* right;
	int data;
};
 
node* newNode(int x)
{
node* temp=new node();
temp->left=NULL;
temp->right=NULL;
temp->data=x;
return temp;
}
void print(node *root)
{
	stack<node*>s;
	
	while(1)
	{
		while(root)
		{
			//cout<<s.top()->data<<" "; // PreOrder
			s.push(root),root=root->left;
		}
		if (s.empty())
			break;
		//cout<<s.top()->data<<" "; // INORDER
		root=s.top()->right;
		s.pop();
		
	}
	
}
int main()
{
	struct node *root = newNode(15);
	root->left = newNode(10);
	root->right = newNode(21);
	root->left->left = newNode(8);
	root->left->right = newNode(12);
	root->left->right->left= newNode(11);
	root->left->right->right = newNode(13);
	root->right->left = newNode(16);
	root->right->right = newNode(25);
	print(root);
	return 0;
}
