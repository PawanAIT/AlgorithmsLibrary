#include<iostream>
using namespace std;
class queue
{
	int a[50];
	int front;
	int rear;
	public:
		queue()
	    {	
	   		rear=front=-1;
	   	}
		void enqueue(int max)
		{
			int x;
			if(front == (rear+1)%max || front == rear+1)
			{
			  	cout<<"\nOverflow\n";
			}
			else
			{
				cout<<"\n\nEnter the value\n";
				cin>>x;
				if(front==-1)
					front=0;
				rear=(rear+1)%max;
				a[rear]=x;
			}        
		}
		int dequeue(int max)
		{
			int num;
			if(front==-1)
			{
		  		cout<<"\nUnderflow\n";
		  		return 0;
			}
	    	if(front==rear)
	    	{
		    	num=a[front];
		    	front=-1;
		    	rear=-1;
		    	return num;
			}
			num=a[front];
			front=(front+1)%max;
			return num;	
		}
		void display(int max)
		{
			int i,temp;
			if(front==-1)
				cout<<"\nYour Queue is Empty";
			else
			{
				cout<<"\nThe elements in the queue are :\n";
				temp = front;
			    while(temp!=rear)
			   	{
					cout<<a[temp]<<"\n";
					temp =(temp+1)%max;
			   	}
			   	cout<<a[temp];
			}
			cout<<"\n\n";
		}
};
int main()  
{
	int ch,max;
	float x,j;
	cout<<"Enter the size of queue\n";
	cin>>max;
	if(max<=0)
	{
		cout<<"\nEnter valid size\n";
	}
	else
	{
		queue q;
		do
		{
			cout<<"\n\nEnter your choice\n1.Insert element into queue\n2.Delete element from queue\n3.Display queue\n4.Exit\n";
			cin>>ch;
			switch(ch)
			{
				case 1: 
					q.enqueue(max);
					break;
				case 2:
					j=q.dequeue(max);
					if(j!=0)
						cout<<"\n\nThe value deleted is "<<j<<"\n";
					break;
				case 3:
					q.display(max);
			    	break;   	       
		       }
		}while(ch<4);
	}	
}
