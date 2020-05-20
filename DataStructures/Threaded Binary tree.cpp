#include<iostream>
using namespace std;

class treenode
{
	public:
		int data;
		treenode *left,*right;
		int lbit,rbit;
};

class tree 
{
	public:
		treenode* create(int n)
		{
			int i,a;
			treenode* root;
			root = new treenode;
			root = NULL;
			for(i=0;i<n;i++)
			{
				cout<<"Enter the node value - ";
				cin>>a;
				root=insert(root,a);
			}
			return root;
		}
		treenode* insert(treenode* root,int a)
		{
			if(root==NULL)
			{
				treenode* root;
				root = new treenode;
				root->data=a;
				root->left=NULL;
				root->right=NULL;
				root->lbit=0;
				root->rbit=0;
				return root;
			}
			else if(a < root->data)
			{
				root->left=insert(root->left,a);
				return root;
			}
			else if(a > root->data)
			{
				root->right=insert(root->right,a);
				return root;
			}
			else if(a==root->data)
			{	
				cout<<"\nNode repetition\n";
				return root;
			}
		}
}
