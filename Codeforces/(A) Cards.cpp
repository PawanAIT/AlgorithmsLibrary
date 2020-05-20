#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	std::vector<int> v;
	int n,q;
	ll sum=0;

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>q;
			v.push_back(q);
			sum+=q;
	}
	sum=sum/(n/2);
	bool visited[105]={0};
	for (int i = 0; i < v.size(); ++i)
	{
		if (visited[i]==0)
		{
			cout<<i+1<<" ";
			visited[i]=1;
			for (int j = 0; j< v.size(); ++j)
			{
				if (v[j]==sum-v[i] && visited[j]==0)
				{
					cout<<j+1<<endl;
					visited[j]=1;
					break;
				}
			}
		}
	}

     
	return 0;
}
