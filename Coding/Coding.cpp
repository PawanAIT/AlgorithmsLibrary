#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
const int N = 100;
vector<int> adj[N];
int visited[N];

const int N = 105;
int visited[N];

bool CheckCycle(int p, vector<int> adj[], int par) {
	visited[p] = 1;

	for (auto i : adj[p]) {

		if (i == par)continue;

		if (visited[i])
			return true;

		if (!visited[i] and CheckCycle(i, adj, p))
			return true;
	}
	return false;
}
bool isCyclic(vector<int> adj[], int V)
{
	bool cycleInGraph = false;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			if (CheckCycle(i, adj, -1))
				cycleInGraph = true;
		}
	}
	return cycleInGraph;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int V, E;
		cin >> V >> E;
		int u, v;
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;

			// adding edge to the graph
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << isCyclic(adj, V) << endl;
	}
}
