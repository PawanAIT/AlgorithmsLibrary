#include "bits/stdc++.h"
#include "CODING.H"
#pragma warning(disable:4996)
using namespace std;
const int N = 100;
vector<int> adj[N];
int indegree[N];
vector<int> TopoOrdering;

void topo(int nodes) {
	for (int i = 1; i <= nodes; i++) { 
		for (auto v : adj[i])
			indegree[v]++;
	}
	queue<int> q;
	for (int i = 1; i <= nodes; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		TopoOrdering.push_back(u);
		for (auto v : adj[u]) {
			indegree[v]--;
			if (indegree[v] == 0)
				q.push(v);
		}
	}
}

void addEdge(int x, int y) {
	x++, y++;
	adj[x].push_back(y);
}

int main() {
	addEdge(5, 2);
	addEdge(5, 0);
	addEdge(4, 0);
	addEdge(4, 1);
	addEdge(2, 3);
	addEdge(3, 1);

	topo(6);

	for (auto i : TopoOrdering) {
		cout << i - 1 << " ";
	}

	return 0;
}

/*
6
7
1 2
2 3
1 3
4 1
4 5
5 6
6 4
*/