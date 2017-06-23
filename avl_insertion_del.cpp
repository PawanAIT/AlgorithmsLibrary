#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data,height;
	node *left,*right;
};

node *getmem(int data)
{
	node * temp=(node*)malloc(sizeof(node));
	temp->left=temp->right=NULL;
	temp->data=data;
	temp->height=1;
	return temp;
}

void postorder(node* p, int indent)
{
    if(p != NULL) {
        if(p->right) {
            postorder(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->data << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->left, indent+4);
        }
    }
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
void preorder(node *root)
{
	if (root)
	{
		cout<<root->data<<" "<<balance(root)<<endl;
		preorder(root->left);
		preorder(root->right);
	}
}
node *leftrotate(node *x)
{
	node *y = x->right;
	
	x->right=y->left;
	y->left =x;
	x->height = 1+max(height(x->left),height(x->right));
	y->height=1+max(height(y->left),height(y->right));
	return y;
}
node *rightrotate(node *x)
{
	node *y=x->left;
	
	x->left = y->right;
	y->right=x;
	x->height = 1+max(height(x->left),height(x->right));
	y->height=1+max(height(y->left),height(y->right));
	return y;
}
node *insert(node *root,int key)
{
	if (root==NULL)
	{
		return getmem(key);
	}
	if (root->data > key)
	{
		root->left=insert(root->left,key);
	}
	else
		root->right=insert(root->right,key);

	root->height = 1+max(height(root->left),height(root->right));
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
node *Delete(node *root,int key)
{
	if (root==NULL)
	{
		return NULL;
	}
	if (root->data > key)
	{
		root->left = Delete(root->left,key);
	}
	else if(root->data < key)
		root->right=Delete(root->right,key);
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
			root->right = Delete(root->right,temp->data);
		}
		return root;
	}
	if (root==NULL)
	{
		return root;
	}
	root->height = 1+max(height(root->left),height(root->right));
	
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
int main()
{
	node *root = NULL;
 	int temp;
 	while(1)
 	{
 		cin>>temp;
 		if(temp==-1)
 			break;
 		root=insert(root,temp);
 		postorder(root,0);
 	}
 	cout<<"hello\n";
 	while(1)
 	{
 		cin>>temp;
 		if ((temp)==-1)
 		{
 			break;
 		}
 		root=Delete(root,temp);
 		postorder(root,0);
 	}

	return 0;
}

/*

14 4 21 3 9 15 28 2 7 10 18 26 35
*/
