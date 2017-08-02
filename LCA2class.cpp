#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100000+5;
vector<int> tree[2 * MAXN];
int depth[2 * MAXN];
int euler[4 * MAXN], eulerIdx=0;
int rmq[20][4 * MAXN];
int first[2 * MAXN];
int logarithm[4 * MAXN + 1];

void dfs(int node, int parent) {
	first[node] = eulerIdx;
	euler[eulerIdx++] = node;
	for (const int& son : tree[node]) {
		if (son != parent) {
			depth[son] = depth[node] + 1;
			dfs(son, node);
			euler[eulerIdx++] = node;
		}
	}
}

void buildTable() {
	logarithm[1] = 0;
	for (int i = 2; i <= eulerIdx; ++i) {
		logarithm[i] = logarithm[i / 2] + 1;
	}
	for (int i = 0; i < eulerIdx; ++i) {
		rmq[0][i] = euler[i];
	}
	for (int i = 1; (1 << i) <= eulerIdx; ++i) {
		for (int j = 0; j + (1 << i) <= eulerIdx; ++j) {
			if (depth[rmq[i - 1][j]] < depth[rmq[i - 1][j + (1 << (i - 1))]]) {
				rmq[i][j] = rmq[i - 1][j];
			}
			else {
				rmq[i][j] = rmq[i - 1][j + (1 << (i - 1))];
			}
		}
	}
}

int lca(int a, int b) {
	a = first[a]; b = first[b];
	if (a > b) {
		swap(a, b);
	}

	int y = logarithm[b - a + 1];
	if (depth[rmq[y][a]] < depth[rmq[y][b - (1 << y) + 1]]) {
		return rmq[y][a];
	}
	return rmq[y][b - (1 << y) + 1];
}


int main() {
	int n, m, q;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y; 
		scanf("%d%d", &x, &y);
		x--; y--;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(0, -1);
	buildTable();
	scanf("%d", &q);
	while (q--) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		a--; b--; c--;
		int x = lca(a, b);
		int y = lca(b, c);
		int z = lca(a, c);
		x++, y++, z++;
		printf("%d\n", x^y^z);
	}
}
