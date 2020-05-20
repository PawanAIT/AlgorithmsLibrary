#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define LD long double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000000007
#define MAXN 2*100005
#define bitcount _builtin_popcount
#define INF 2000000000
#define EPS 1e-9

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

vector<int> G[MAXN];

void dfs(int node,stack<int> &S, vector<bool> &visited)
{
	visited[node] = true;
	vector<int>::iterator it;
	for (it = G[node].begin(); it != G[node].end(); it++)
	{
		if (!visited[*it])
		{
			dfs(*it, S, visited);
		}
	}
	S.push(node);
}
void TopologicalSorting(int N, int M)
{
	vector<bool> visited(M, false);
	stack<int> S;
	for (int i = 0; i < M; i++)
	{
		if (!visited[i])
		{
			dfs(i, S, visited);
		}
	}
	cout << "The Topological Sorting for the following graph is :-\n";
	while (!S.empty())
	{
		cout << S.top() << " ";
		S.pop();
	}
	cout << endl;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < MAXN; i++)
	{
		G[i].clear();
	}

	int U, V;
	for (int i = 0; i < N; i++)
	{
		cin >> U >> V;
		G[U].pb(V);
	}
	//cout<<"wow"<<endl;
	TopologicalSorting(N, M);
	return 0;
}