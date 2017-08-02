#include<bits/stdc++.h>
using namespace std;
class LCA
{
public:
	LCA(int n) {
		adj.resize(n);
		first.resize(n);
		input(n);
		dfs(0, -1);
		build();

	}
	int Query(int u, int v) {
		u--, v--;
		int fe1 = first[u];
		int fe2 = first[v];
		if (fe1 > fe2)
			swap(fe1, fe2);
		int foo = minimum(fe1, fe2 + 1);
		int bar = NewtoOld[foo];
		return bar+1;
	}
private:
	vector<int> logarithm;
	vector<vector<int>> sparse;
	vector<vector<int>> adj;
	vector<int> euler;
	vector<int> first;
	vector<int> NewtoOld;

	void dfs(int v, int p) {
		int idx = NewtoOld.size();
		NewtoOld.push_back(v);
		first[v] = euler.size();
		euler.push_back(idx);
		for (int u : adj[v]) {
			if (u == p)
				continue;
			dfs(u, v);
			euler.push_back(idx);
		}
	}
	void input(int n) {
		int u, v;
		for (int i = 0; i < n - 1; i++) {
			scanf("%d%d", &u, &v);
			u--, v--;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
	}
	void build() {
		logarithm.assign(euler.size() + 1, 0);
		for (int i = 2; i < logarithm.size(); i++)
			logarithm[i] = logarithm[i / 2] + 1;

		sparse.assign(logarithm.back() + 1, vector<int>(euler.size()));
		sparse[0] = euler;
		for (int row = 1; row < sparse.size(); row++) {
			for (int i = 0; i + (1 << row) <= euler.size(); i++) {
				sparse[row][i] = min(sparse[row - 1][i], sparse[row - 1][i + (1 << (row - 1))]);
			}
		}
	}

	int minimum(int l, int r) {
		int log = logarithm[r - l];
		return min(sparse[log][l], sparse[log][r - (1 << log)]);
	}

};

int main()
{
	int n,u,vv;
	scanf("%d", &n);	
	static LCA obj(n);
	int q;
	scanf("%d", &q);
	while (q--) {
		int x, y, z;
		scanf("%d%d%d", &x,&y,&z);
		int a = obj.Query(x, y);
		int b = obj.Query(y, z);
		int c = obj.Query(x, z);
		printf("%d\n", a^b^c);
	}
	return 0;
}
 
