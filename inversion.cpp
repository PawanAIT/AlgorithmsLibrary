#include "bits/stdc++.h"
using namespace std;
vector<pair<int,int> > v[100005];
bool visited[100005];
int distance[100005];
int parent[100005];
priority_queue<pair<int,int> >Q;
void print(int x)
{
	if (parent[x]==-1)
	{
		return ;
	}
	int ans=parent[x];
	print(parent[x]);
	cout<<ans<<" ";
}
int main()
{	
	int m,n;
	cin>>n>>m;
	int one ,two ,weight;	
	for (int i = 0; i < m; ++i)
	{
		cin>>one>>two>>weight;
		v[one].push_back({two,weight});
		v[two].push_back({one,weight});
	}
	Q.push({0,1});
	distance[1]=0,parent[1]=-1;
	while(!Q.empty())
	{

		pair<int,int> temp=Q.top();
		int u=temp.second;
		if (u==n)
		{
				break;
		}
		if (!visited[u])
		{
			continue;
		}
		visited[u]=true;
		for (int i = 0; i < v[u].size(); ++i)
		{
			int dist=v[u][i].first;
			int next=v[u][i].second;
			if (distance[next]>distance[u]+dist)
			{
				distance[next]=distance[u]+dist;
				parent[next]=u;
				Q.push(distance[next],next);
			}
		}
	}

	if (distance[n]==INT_MAX)
	{
		cout<<-1;
	}
	else
		print(n);
	

     
	return 0;
}