#include<iostream>
#include<stack>
#include<utility>
#include<vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 150

vector<int> G[MAXN];

bool dfs(int node,vector<bool> &recstack,vector<bool> &visited)
{
	visited[node] = true;
	recstack[node] = true;
	vector<int>::iterator it;
	for(it = G[node].begin(); it != G[node].end(); it++)
	{
		if(!visited[*it]&&dfs(*it,recstack,visited))
		{
			return true;
		}
		if(recstack[*it])
		{
			return true;
		}
	}
	recstack[node]=false;
	return false;
}
bool CycleDetectionDirected(int M)
{
	vector<bool> visited(M, false);
	vector<bool> recstack(M, false);
	for(int i = 0; i < M; i++)
	{
		if(dfs(i, recstack, visited))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < MAXN; i++)
	{
		G[i].clear();
	}

	int U, V;
	for(int i = 0; i < N; i++)
	{
		cin >> U >> V;
		G[U].pb(V);
	}
	//cout<<"wow"<<endl;
	if(CycleDetectionDirected(M))
	{
		cout<<"Cycle Detected\n";
	}
	else
	{
		cout<<"No Cycle\n";
	}
	return 0;
}