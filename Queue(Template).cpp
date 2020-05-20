#include <iostream>
using namespace std;

template<typename T> class Queue
{
	int sz;
	T *A;
	int fronts,rears;
	public:
		Queue()
		{
			sz=0;
			fronts=-1,rears=-1;
			A=new T[sz];
		}
	
		Queue(int S)
		{
			sz=S;
			fronts=-1,rears=-1;
			A=new T[S];
		}
	
		void enqueue(T el)
		{
			if((fronts+1)%sz==rears||rears==-1&&fronts==sz-1)
			{
				printf("Queue Overflow\n");
			}
			else 
			{
				fronts=(fronts+1)%sz;
				A[fronts]=el;
			}
		}
	
		void dequeue()
		{	
			if(rears==fronts)
			{
				printf("Queue Underflow\n");
			}
			else 
			{
				rears=(rears+1)%sz;
			}
		}
		
		T front()
		{
			if(fronts!=rears)
			{
				return A[fronts];
			}
			else
			{
				cout<<"Nothing to show\n";
				return -1;
			}
		}
};

int main()
{
	Queue<int> Q(3);
	Q.enqueue(4);
	Q.enqueue(45);
	cout<<Q.front()<<endl;
	Q.enqueue(23);
	Q.enqueue(53);
	Q.dequeue();
	cout<<Q.front()<<endl;
	Q.dequeue();
	Q.dequeue();
	Q.dequeue();
	Q.dequeue();
	Q.enqueue(33);
	cout<<Q.front()<<endl;
	return 0;
}