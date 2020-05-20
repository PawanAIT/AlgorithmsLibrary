#include<iostream>
using namespace std;
class node
{
	public:
		char data;
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
		void push(char x)
		{
			node* n;
			n = new node;
			n->data = x;
			n->next = top;
			top = n;
		}	
		char pop()
		{
			char x;
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
		char peek()
		{	
			if(top==NULL)
				return -1;
			else
				return top->data;
		}
};

int precedence(char oper)
{
	if(oper=='+' || oper=='-')
		return 1;
	if(oper=='*' || oper=='/')
		return 2;
	if(oper=='^')
		return 4;
	return 5;
}

int precedence1(char oper)
{
	if(oper=='(')
		return -1;
	if(oper=='+' || oper=='-')
		return 1;
	if(oper=='*' || oper=='/')
		return 2;
	if(oper=='^')
		return 3;
	return 5;
}

int main()
{
	stack s;
	int i,j=0;
	char infix[20],postfix[20];
	cin>>infix;
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]>=97 && infix[i]<=122)
		{
			postfix[j++]=infix[i];
		}
		else
		{
			if(!s.isempty())
				s.push(infix[i]);
			else
			{
				if(infix[i]==')')
				{
					while(s.peek()!='(')
						postfix[j++]=s.pop();
					char d=s.pop();
				}
				else
				{
					while(precedence(infix[i])<=precedence1(s.peek()) && s.isempty())
					{
						postfix[j++]=s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(s.isempty())
	{
		postfix[j++]=s.pop();
	}
	postfix[j]='\0';
	cout<<postfix;
	return 0;
}














