#include<iostream>
#define MAX 20
using namespace std;

class stack
{
		int top;
		int data[MAX];
	public:
		stack()	
		{
			top=-1;
		}
		void push(int x)
		{
			top++;
			data[top]=x;
		}
		int pop()
		{
			return data[top--];
		}
		int full()
		{
			if(top==MAX-1)
				return 1;
			else
				return 0;
		}
		int empty()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
		int peek()
		{
			return data[top];
		}
		void display()
		{
			int i=top;
			while(i>=0)
			{
				cout<<"\n"<<data[i]<<"\n";
				i--;
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
					if(s.full()==0)
						s.push(x);
					else 
						cout<<"Stack is Full\n";
					break;
			case 2:
					if(s.empty()==0)
						cout<<"\n"<<s.pop()<<"\n";
					else 
						cout<<"Stack is Empty\n";
					break;
			case 3:
					cout<<"\n"<<s.peek()<<"\n";
					break;
			case 4:
					s.display();
					break;
		}
	}while(i!=0);
	return 0;
}














