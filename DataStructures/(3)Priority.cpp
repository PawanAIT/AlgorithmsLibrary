#include<iostream>
using namespace std;
#define max 5
typedef struct node
{
	int data;
	node *next;
}node;
typedef struct q
{
	node *front;
	node *rear;	
}q;
class pqueue
{
	public :
	void initialise(q pri[])
	{
		int i;
		for(i=0;i<max;i++)
		{
				pri[i].rear=NULL;
				pri[i].front=NULL;
		}
	}
	int empty(q *fr)
	{
		if(fr->rear==NULL)
			return 1;
		else
			return 0;
	}	
	void enqueue(q *fr,int a)
	{	
		node *p;
		p = new node();
		
		p->data=a;
		p->next=NULL;
		if(fr->rear==NULL)
		{
			
			fr->front=p;
			fr->rear=p;
		}
		else
		{
			fr->rear->next=p;
			fr->rear=p;
		}
		
	}
	int dequeue(q *fr)
	{
		node *p;
		int x;
		p=fr->front;
		if(fr->front==fr->rear)
		{
			fr->front=NULL;
			fr->rear=NULL;	
		}
		else
		{
			fr->front=fr->front->next;
		}
		x=p->data;
		delete(p);
		return x;
	}
	void print(q fr[])
	{
		node *p;
		int i,check=0;
		for( i=max-1;i>=0;i--)
		{	
			cout<<"queue no-"<<i<<":";
			if(fr[i].front!=NULL)
			{
				p=fr[i].front;
				while(p!=NULL)
				{
					cout<<p->data<<" ";
					p=p->next;
				}
			}
			else
			{
				cout<<"this queue is empty";
				check++;
			}
		cout<<"\n";	
		}
		if(check==max)
		cout<<"all queues are empty";
	}
};
int main()
{
	q pri[max];
	pqueue obq;
	int element,x,quepriority;
	obq.initialise(pri);
	
	do
	{
		cout<<"1.enqueue\n2.dequeue\n3.print\n4.exit\nenter choice:";
		cin>>x;
		switch(x)
		{
			case 1:
				do
				{
				cout<<"enter valid queue priority:";
				cin>>quepriority;
				}while(!(quepriority<max && quepriority>-1));
				cout<<"enter the element:";
				cin>>element;
				obq.enqueue(&pri[quepriority],element);
				break;
			case 2:
				quepriority=max-1;
				while(obq.empty(&pri[quepriority]))
				{
					quepriority--;
					if(quepriority<0)
						break;
				}
				if(quepriority==-1)
					cout<<"all queues are empty\n";
				else
				{
					element=obq.dequeue(&pri[quepriority]);
					cout<<element<<" is deleted\n";
				}
				break;
				
			case 3:
				obq.print(pri);
				break;
			default:
				cout<<"You entered a wrong choice\n";
				break;
		}
	}while(x!=4);
	
	return 0;
}
