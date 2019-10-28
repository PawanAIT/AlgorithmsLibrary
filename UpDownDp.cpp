#include "bits/stdc++.h"
using namespace std;
#pragma warning(disable:4996)
vector<int> cities;
const int N = 1e5 + 5;
vector<int> G[N];
int distup[N], distdown[N];

int dfsdown(int u, int p) {
	int dist = 0;
	for (auto v : G[u]) 
	{
		if (v != p)
		{
			dist = max(dist , dfsdown(v, u));
		}
	}
	distdown[u] = dist;
	dist++;
	return dist;
}

void dfsup(int u, int p) {
	int firstmax = -1, secondmax = -1;

	for (auto v : G[u]) {
		if (v != p) {
			if (firstmax < distdown[v]) {
				secondmax = firstmax;
				firstmax = distdown[v];
			}
			else if (distdown[v] > secondmax) {
				secondmax = distdown[v];
			}
		}
	}

	for (auto v : G[u]) {
		if (v != p) {
			int dist = (distdown[v] + 1 == distdown[u]) ? secondmax : firstmax;
			distup[v] = 1 + max(distup[u], 1 + dist);
			dfsup(v, u);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfsdown(1, -1);
	dfsup(1, -1);
	int ans = 0;
	//for (int i = 1; i <= n; i++) {
	//	cout << distdown[i] << " ";
	//}
	//cout << endl;
	//for (int i = 1; i <= n; i++) {
	//	cout << distup[i] << " ";
	//}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, distup[i] + distdown[i]);
	}
	printf("%d\n", ans);
}

/*
6
1 2
1 3
3 4
4 5
3 6
*/