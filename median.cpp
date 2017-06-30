#include <bits/stdc++.h>
using namespace std;
priority_queue<double,std::vector<double>,greater<double>> minheap;
priority_queue<double> maxheap;
double add(double n)
{
	if (maxheap.size()==0)
	{
		maxheap.push(n);
	}
	else if(maxheap.top() > n)
	{
		maxheap.push(n);
	}
	else
		minheap.push(n);

	if(abs((double)minheap.size()-(double)maxheap.size()) > 1)
	{
		if(minheap.size()>maxheap.size())
		{
			double temp=minheap.top();
			minheap.pop();
			maxheap.push(temp);
		}
		else
		{
			double temp=maxheap.top();
			maxheap.pop();
			minheap.push(temp);
		}
	}
	int total =minheap.size()+maxheap.size();
	if(total%2)
		return maxheap.size()<minheap.size()?minheap.top():maxheap.top();
	else
		return (minheap.top()+maxheap.top())/2.0;
}
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",(int)add(n));
	}
	return 0;
}