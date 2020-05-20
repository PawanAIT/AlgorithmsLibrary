#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{	
	//ios::sync_with_stdio(0); cin.tie(0);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		std::vector<pair<int,int> > v[100005];
		int visited[100005];
		memset(visited,-1,sizeof(visited));
		int n,x,y,weight;
		scanf("%d",&n);
		for (int i = 0; i < n-1; ++i)
		{
			scanf("%d%d%d",&x,&y,&weight);
			v[x].push_back(make_pair(y,weight));
			v[y].push_back(make_pair(x,weight));
		}
		int max=INT_MIN,max_idx,max_val;
		queue<pair<int,int> >Q;
		int val,idx;
		pair<int,int> p;
		Q.push(v[x].front());
		visited[v[x].front().first]=0;
		while(!Q.empty())
		{
			p=Q.front();
			Q.pop();
			idx=p.first;
			val=p.second;
			for (int i = 0; i < v[idx].size(); ++i)
			{
				int index=v[idx][i].first;
				int value =v[idx][i].second;
				if (visited[index]==-1)
				{
					Q.push(v[idx][i]);
					visited[index]=visited[idx]+value;
					if(visited[index] > max)
					{
						max=visited[index];
						max_idx=index;
						max_val=value;
					}
				}
			}
		}
		memset(visited,-1,sizeof(visited));
		Q.push(make_pair(max_idx,max_val));
		visited[max_idx]=0;

		while(!Q.empty())
		{
			p=Q.front();
			Q.pop();
			idx=p.first;
			val=p.second;
			for (int i = 0; i < v[idx].size(); ++i)
			{
				int index=v[idx][i].first;
				int value =v[idx][i].second;
				if (visited[index]==-1)
				{
					Q.push(v[idx][i]);
					visited[index]=visited[idx]+value;
					if(visited[index] > max)
					{
						max=visited[index];
					}
				}
			}
		}
		printf("%d\n", max);
	}

     
	return 0;
}
