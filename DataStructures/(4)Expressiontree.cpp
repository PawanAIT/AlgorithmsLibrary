#include<iostream>
using namespace std;

class treenode
{
	public:
		char data;
		int flag;
		treenode *left,*right;
};

class stacknode
{
	public:
		treenode* link;
		stacknode* next; 
};

class stack
{ 
		stacknode* top;
	public:
		stack()
		{
			top=NULL;
		}
		void push(treenode* x)
		{
			stacknode* n;
			n = new stacknode;
			n->link = x;
			n->next = top;
			top = n;
		}	
		treenode* pop()
		{
			treenode* x;
			stacknode *p;
			p=top;
			top=top->next;
			x=p->link;
			delete p;
			return x;
		}
		int isempty()
		{
			if(top==NULL)
				return 0;
			else 
				return 1;
		}
};

class tree{
	public:
		treenode* create(char x)
		{
			treenode* leaf;
			leaf = new treenode;
			leaf->data=x;
			leaf->flag=0;
			leaf->left=NULL;
			leaf->right=NULL;
			return leaf;
		}
		treenode* maintain(char r, treenode* x, treenode* y)
		{
			treenode* exp;
			exp = new treenode;
			exp->data = r;
			exp->flag = 0;
			exp->left=x;
			exp->right=y;
			return exp;
		}
		void preorder(treenode* z)
		{
			if(z!=NULL)
			{
				cout<<z->data<<" ";
				preorder(z->left);
				preorder(z->right);
			}
		}
		void inorder(treenode* z)
		{
			if(z!=NULL)
			{
				inorder(z->left);
				cout<<z->data<<" ";
				inorder(z->right);
			}
		}
		void postorder(treenode* z)
		{
			if(z!=NULL)
			{
				postorder(z->left);
				postorder(z->right);
				cout<<z->data<<" ";
			}
		}
		void nonpre(treenode* z)
		{
			stack s;
			while(z!=NULL)
			{
				cout<<z->data<<" ";
				s.push(z);
				z=z->left;
			}
			while(s.isempty())
			{
				z=s.pop();
				z=z->right;
				while(z!=NULL)
				{
					cout<<z->data<<" ";
					s.push(z);
					z=z->left;
				}
			}
		}
		void nonin(treenode* z)
		{
			stack s;
			while(z!=NULL)
			{
				s.push(z);
				z=z->left;
			}
			while(s.isempty())
			{
				z=s.pop();
				cout<<z->data<<" ";
				z=z->right;
				while(z!=NULL)
				{
					s.push(z);
					z=z->left;
				}
			}
		}
		void nonpost(treenode* z)
		{
			stack s;
			while(z!=NULL)
			{
				s.push(z);
				z=z->left;
			}
			while(s.isempty())
			{
				z=s.pop();
				if(z->flag==0)
				{
					z->flag=1;
					s.push(z);
					z=z->right;
					while(z!=NULL)
					{
						s.push(z);
						z=z->left;
					}
				}
				else
				{
					cout<<z->data<<" ";
				}
			}
		}
};

int main()
{
	stack s;
	tree t;
	int i,ch;
	char postfix[20];
	cout<<"Enter the Postfix Expression\n";
	cin>>postfix;
	cout<<"\n";
	for(i=0;postfix[i]!='\0';i++)
	{
		if(postfix[i]>=97 && postfix[i]<=122)
		{
			s.push(t.create(postfix[i]));
		}
		else
		{
			treenode *x,*y;
			y=s.pop();
			x=s.pop();
			s.push(t.maintain(postfix[i],x,y));
		}
	}
	treenode * z = s.pop();
	do{
		cout<<"--------------------------------------------\n";
		cout<<"--------------------------------------------\n";
		cout<<"\n1.Preorder Traversal";
		cout<<"\n2.Inorder Traversal";
		cout<<"\n3.Postorder Traversal";
		cout<<"\n4.Non-Recursive Preorder Traversal";
		cout<<"\n5.Non-Recursive Inorder Traversal";
		cout<<"\n6.Non-Recursive Postorder Traversal";
		cout<<"\n0.EXIT";
		cout<<"\n\nEnter your Choice - ";
		cin>>ch;
		cout<<"\n";
		switch(ch)
		{
			case 1:
				cout<<"Preorder Traversal  ";
				t.preorder(z);
				cout<<"\n\n";
				break;
			case 2:
				cout<<"Inorder Traversal  ";
				t.inorder(z);
				cout<<"\n\n";
				break;
			case 3:
				cout<<"Postorder Traversal  ";
				t.postorder(z);
				cout<<"\n\n";
				break;
			case 4:
				cout<<"Non-Recursive Preorder Traversal  ";
				t.nonpre(z);
				cout<<"\n\n";
				break;
			case 5:
				cout<<"Non-Recursive Inorder Traversal  ";
				t.nonin(z);
				cout<<"\n\n";
				break;
			case 6:
				cout<<"Non-Recursive Postorder Traversal  ";
				t.nonpost(z);
				cout<<"\n\n";
				break;
		}
	}while(ch!=0);
	return 0;
}






