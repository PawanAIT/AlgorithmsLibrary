#include <bits/stdc++.h>
using namespace std;
class orderstat
{
private:
	struct node
	{
		int data,height,size;
		node *left,*right;
	};
	node *root;

	node *getmem(int data)
	{
		node * temp=(node*)malloc(sizeof(node));
		temp->left=temp->right=NULL;
		temp->data=data;
		temp->height=1;
		temp->size = 1;
		return temp;
	}


	int size(node *x)
	{
		if(x==NULL)
		{
			return 0;
		}
		return x->size;
	}
	int height(node *x)
	{
		if (x==NULL)
		{
			return 0;
		}
		return x->height;
	}
	int balance(node *x)
	{
		if (x==NULL)
		{
			return 0;
		}
		return height(x->left)-height(x->right);
	}
	node *leftrotate(node *x)
	{
		node *y = x->right;
		
		x->right=y->left;
		y->left =x;
		x->height = 1+max(height(x->left),height(x->right));
		y->height=1+max(height(y->left),height(y->right));
		x->size = 1+size(x->left) + size(x->right);
		y->size = 1+size(y->left) + size(y->right); 
		return y;
	}
	node *rightrotate(node *x)
	{
		node *y=x->left;
		
		x->left = y->right;
		y->right=x;
		x->height = 1+max(height(x->left),height(x->right));
		y->height=1+max(height(y->left),height(y->right));
		x->size = 1+size(x->left) + size(x->right);
		y->size = 1+size(y->left) + size(y->right); 
		return y;
	}
	node *_insert(node *root,int key)
	{
		if (root==NULL)
		{
			return getmem(key);
		}
		if (root->data > key)
		{
			root->left=_insert(root->left,key);
		}
		else
			root->right=_insert(root->right,key);

		root->height = 1+max(height(root->left),height(root->right));
		root->size = 1+size(root->left) + size(root->right); 
		int bal=balance(root);
		if (bal > 1)
		 {
		 	if ( balance(root->left)>=0)
		 	{
		 		return rightrotate(root);
		 	}
		 	else
		 	{
		 		root->left = leftrotate(root->left);
		 		return rightrotate(root);
		 	}
		 }
		 if (bal < -1)
		 {
		 	if ( balance(root->right) <=0 )
		 	{
		 		return leftrotate(root);
		 	}
		 	else
		 	{
		 		root->right = rightrotate(root->right);
		 		return leftrotate(root); 
		 	}
		 }
		 return root;
	}
	node *_delete(node *root,int key)
	{
		if (root==NULL)
		{
			return NULL;
		}
		if (root->data > key)
		{
			root->left = _delete(root->left,key);
		}
		else if(root->data < key)
			root->right=_delete(root->right,key);
		else
		{
			if (root->left==NULL&&root->right==NULL)
			{
				free(root);
				root=NULL;
			}
			else if(root->left==NULL)
			{
				node *temp=root->right;
				*root = *(root->right);
				free(temp);
			}
			else if(root->right==NULL)
			{
				node *temp =root->left;
				*root=*(root->left);
				free(temp);
			}
			else
			{
				node *temp=root->right;
				while(temp->left!=NULL)
					temp=temp->left;
				root->data = temp->data;
				root->right = _delete(root->right,temp->data);
			}
			return root;
		}
		if (root==NULL)
		{
			return root;
		}
		root->height = 1+max(height(root->left),height(root->right));
		root->size = 1 + size(root->left) + size(root->right);
		int bal=balance(root);
		if (bal > 1)
		 {
		 	if ( balance(root->left)>=0)
		 	{
		 		return rightrotate(root);
		 	}
		 	else
		 	{
		 		root->left = leftrotate(root->left);
		 		return rightrotate(root);
		 	}
		 }
		 if (bal < -1)
		 {
		 	if ( balance(root->right) <=0 )
		 	{
		 		return leftrotate(root);
		 	}
		 	else
		 	{
		 		root->right = rightrotate(root->right);
		 		return leftrotate(root); 
		 	}
		 }
		return root;
	}
	int _order(node *root,int x)
	{
		if(size(root->left) + 1==x)
		{
			return root->data;
		}
		if(size(root->left) < x)
		{
			return _order(root->right,x - size(root->left) -1 );
		}
		else 
			return _order(root->left,x);
	}
public:
	orderstat()
	{
		root = NULL;
	}
	int order(int x)
	{
		if(x>size(root))
			return 0;
		return _order(root,x);
	}
	void insert(int x)
	{
		root = _insert(root,x);
	}
	void Delete(int x)
	{
		root = _delete(root,x);
	}
};
int main()
{
	
 	orderstat X;
 	X.insert(5);
 	X.insert(7);
 	cout<<X.order(2);
 	X.Delete(7);
 	cout<<X.order(1);
 	cout<<X.order(2); // cant Find hence zero MOFO !
	return 0;
}
