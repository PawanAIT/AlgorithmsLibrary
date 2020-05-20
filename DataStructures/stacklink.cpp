#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next; 
};

class stack
{ 
		node* top;
	public:
		stack()
		{
			top=NULL;
		}
		void push(int x)
		{
			node* n;
			n = new node;
			n->data = x;
			n->next = top;
			top = n;
		}	
		int pop()
		{
			int x;
			node *p;
			p=top;
			top=top->next;
			x=p->data;
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
		void peek()
		{	
			cout<<top->data<<"\n";
		}
		void display()
		{
			node* p=top;
			while(p!=NULL)
			{
				cout<<"\n"<<p->data<<"\n";
				p=p->next;
			}
		}
};

int main()
{
	stack s;
	int x,i;
	do
	{
		cout<<"1.Push\n";
		cout<<"2.Pop\n";
		cout<<"3.Display top\n";
		cout<<"4.Display all\n";
		cout<<"0.Exit\n";
		cin>>i;
		switch(i)
		{
			case 1:
					cout<<"Enter the element to fill the stack\n";
					cin>>x;
					s.push(x);
					break;
			case 2:
					if(s.isempty()==1)
						cout<<"\n"<<s.pop()<<"\n";
					else 
						cout<<"Stack is Empty\n";
					break;
			case 3:
					s.peek();
					break;
			case 4:
					s.display();
					break;
		}
	}while(i!=0);
	return 0;
}












