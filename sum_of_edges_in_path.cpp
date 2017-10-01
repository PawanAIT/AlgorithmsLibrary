#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 
#define MAXN 100000
#define MAXLOG 18
 
int h[MAXN]; 
int par[MAXN][MAXLOG]; // initially all -1
int cost[MAXN][MAXLOG];
vector <int> adj[MAXN], adj_costs[MAXN];
 
void dfs(int v,int p = -1, int c = -1){
	par[v][0] = p;
	cost[v][0] = c;
	if(p + 1)
		h[v] = h[p] + 1;
	for(int i = 1;i < MAXLOG;i ++)
		if(par[v][i-1] + 1){
			par[v][i] = par[par[v][i-1]][i-1];
			cost[v][i] = cost[v][i-1]+ cost[par[v][i-1]][i-1];
		}
	vector<int>::iterator j=adj_costs[v].begin();
	for(vector<int>::iterator u=adj[v].begin(); u!=adj[v].end(); ++u,++j )	
		if(p - *u)
			dfs(*u,v,*j);
}
 
int LCA_sum(int v,int u){   // returns the sum of edges in the path u to v
	int res=0;
	if(h[v] < h[u])
		swap(v,u);
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] + 1 and h[par[v][i]] >= h[u]){
			res+=cost[v][i];
			v = par[v][i];
		}
	// now h[v] = h[u]
	if(v == u)
		return res;
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] - par[u][i]){
			res+=cost[v][i]+cost[u][i];
			v = par[v][i], u = par[u][i];
		}
	return res+cost[v][0]+cost[u][0];
}
 
int main() {
	memset(par, -1, sizeof(par));
	int n;
	cin>>n;
	for(long i=1; i<n; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			u--; v--;
			adj[u].push_back(v);
			adj_costs[u].push_back(c);
			adj[v].push_back(u);
			adj_costs[v].push_back(c);
	}
	h[0]=0;
	dfs(0);
	int q;
	cin>>q;
	while(q--){
		int a, b;
		cin>>a>>b;
		cout<<LCA_sum(a-1, b-1)<<endl;
	}
	return 0;
}
