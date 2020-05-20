#include <iostream>
using namespace std;

template<typename T> class Stack
{
	int sz;
	T *A;
	int tops;
	public:
		Stack()
		{
			sz=0;
			tops=-1;
			A=new T[sz];
		}
	
		Stack(int S)
		{
			sz=S;
			tops=-1;
			A=new T[S];
		}
	
		void push(T el)
		{
			if(tops==sz-1)
			{
				printf("Stack Overflow\n");
			}
			else if(tops<sz-1)
			{
				++tops;
				A[tops]=el;
			}
		}
	
		void pop()
		{	
			if(tops==-1)
			{
				printf("Stack Underflow\n");
			}
			else if(tops>-1)
			{
				--tops;
			}
		}
		
		T top()
		{
			return A[tops];
		}
};

int main()
{
	Stack<int> S(3);
	S.push(4);
	S.push(45);
	cout<<S.top()<<endl;
	S.push(23);
	S.push(53);
	S.pop();
	S.pop();
	S.pop();
	S.pop();
	S.pop();
	S.push(33);
	cout<<S.top()<<endl;
	return 0;
}