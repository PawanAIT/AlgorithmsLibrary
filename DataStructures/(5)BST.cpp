#include<iostream>
using namespace std;

class treenode
{
	public:
		int data;
		treenode *left,*right;
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
		treenode* search(treenode* root,int a)
		{
			if(root==NULL)
			{
				cout<<"\nNode not found";
				return root;
			}
			else if(a < root->data)
			{
				root->left=search(root->left,a);
				return root;
			}
			else if(a > root->data)
			{
				root->right=search(root->right,a);
				return root;
			}
			else if(a==root->data)
			{	
				cout<<"\nNode found - ";
				cout<<root->data;
				return root;
			}	
		}
		treenode* delete1(treenode* root,int a)
		{
			if(root==NULL)
			{
				cout<<"\nNode not found\n";
				return root;
			}
			else if(a < root->data)
			{
				root->left=delete1(root->left,a);
				return root;
			}
			else if(a > root->data)
			{
				root->right=delete1(root->right,a);
				return root;
			}
			else if(a==root->data)
			{	
				treenode* temp;
				temp=root;
				if(root->left!=NULL && root->right!=NULL)
				{
					temp=min(root->right);
					root->data=temp->data;
					root->right=delete1(root->right,temp->data);
					return root;
				}
				else if(root->left!=NULL && root->right==NULL)
				{
					root=root->left;
					delete temp;
					return root;
				}
				else if(root->right!=NULL && root->left==NULL)
				{
					root=root->right;
					delete temp;
					return root;
				}
				delete temp;
				return (NULL);
			}	
		}
		treenode* min(treenode* root)
		{
			while(root->left!=NULL)
				root=root->left;
			return root;
		}
		void preorder(treenode* root)
		{
			if(root!=NULL)
			{
				cout<<root->data<<" ";
				preorder(root->left);
				preorder(root->right);
			}
		}
		void inorder(treenode* root)
		{
			if(root!=NULL)
			{
				inorder(root->left);
				cout<<root->data<<" ";
				inorder(root->right);
			}
		}
		void postorder(treenode* root)
		{
			if(root!=NULL)
			{
				postorder(root->left);
				postorder(root->right);
				cout<<root->data<<" ";
			}
		}
};

int main()
{
	tree t;
	int n,a,ch;
	treenode* root;
	cout<<"Enter the no. of nodes of BST - ";
	cin>>n;
	root = t.create(n);
	cout<<"\nPreorder Traversal - ";
	t.preorder(root);
	cout<<"\n\n";
	do{
		cout<<"--------------------------------------------\n";
		cout<<"--------------------------------------------\n";
		cout<<"\n1.Insert new node in BST";
		cout<<"\n2.Search node in BST";
		cout<<"\n3.Delete node in BST";
		cout<<"\n4.Preorder Traversal";
		cout<<"\n5.Inorder Traversal";
		cout<<"\n6.Postorder Traversal";
		cout<<"\n0.EXIT";
		cout<<"\nEnter your choice - ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the node to be inserted - ";
				cin>>a;
				root = t.insert(root,a);
				cout<<"\nPreorder Traversal - ";
				t.preorder(root);
				cout<<"\n\n";
				break;
			case 2:
				cout<<"\nEnter the node to be searched - ";
				cin>>a;
				root = t.search(root,a);
				cout<<"\n\n";
				break;
			case 3:
				cout<<"\nEnter the node to be deleted - ";
				cin>>a;
				root = t.delete1(root,a);
				cout<<"\nPreorder Traversal - ";
				t.preorder(root);
				cout<<"\n\n";
				break;
			case 4:
				cout<<"\nPreorder Traversal - ";
				t.preorder(root);
				cout<<"\n\n";
				break;
			case 5:
				cout<<"\nInorder Traversal - ";
				t.inorder(root);
				cout<<"\n\n";
				break;
			case 6:
				cout<<"\nPostorder Traversal - ";
				t.postorder(root);
				cout<<"\n\n";
				break;
		}
	}while(ch!=0);
	return 0;
}






