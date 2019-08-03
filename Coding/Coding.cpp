#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
const int N = 100;
vector<int> adj[N];
int visited[N];

enum { WHITE, GREY, BLACK };

bool CheckCycle(int p) {
	visited[p] = GREY;

	for (auto i : adj[p]) {

		if (visited[i] == GREY)
			return true;

		if (visited[i] == WHITE and CheckCycle(i))
			return true;
	}

	visited[p] = BLACK;
	return false;
}

int main() {
	//freopen("input.txt", "r+", stdin);
	
	int nodes, edges;
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	bool cycleInGraph = false;

	for (int i = 1; i <= nodes; i++) {
		if (visited[i] == WHITE) {
			if (CheckCycle(i))
				cycleInGraph = true;
		}
	}

	cout << (cycleInGraph ? "Cycle" : "No Cycle");
	
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