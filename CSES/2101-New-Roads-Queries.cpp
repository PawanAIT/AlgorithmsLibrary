#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXLOG = 20;

vector<pair<int,int>> tree[MAXN];
int parent[MAXN][MAXLOG], depth[MAXN], max_weight[MAXN][MAXLOG];
int vis[MAXN];

void dfs(int node, int par, int d = 1) {
    parent[node][0] = par;
    depth[node] = d;
    vis[node] = 1;
    for (auto edge : tree[node]) {
        int child = edge.first;
        int weight = edge.second;
        if (child != par) {
            max_weight[child][0] = weight;
            dfs(child, node, d + 1);
        }
    }
}

void preprocess(int n) {
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i, -1);
    }

    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= n; j++) {
            if (parent[j][i - 1] != -1) {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
                max_weight[j][i] = max(max_weight[j][i - 1], max_weight[parent[j][i - 1]][i - 1]);
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if ((diff >> i) & 1) {
            u = parent[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int query(int u, int v) {
    int ans = 0;
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if ((diff >> i) & 1) {
            ans = max(ans, max_weight[u][i]);
            u = parent[u][i];
        }
    }
    if (u == v) {
        return ans;
    }
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            ans = max(ans, max(max_weight[u][i], max_weight[v][i]));
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    ans = max(ans, max(max_weight[u][0], max_weight[v][0]));
    return ans;
}

class dsu{
    vector<int> p;
    public:
    dsu(int n){
        p.resize(n + 1);
        for(int i = 0; i <= n; i++) p[i] = i;
    }
    int find(int x){
        if(x != p[x]){
            return p[x] = find(p[x]);
        }
        return x;
    }
    bool Union(int x, int y){
        x = find(x), y = find(y);
        if(x != y){
            p[x] = y;
            return true;
        }
        return false;
    }
    bool sameComp(int x, int y){
        return find(x) == find(y);
    }
};
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int N, E, Q, u, v;
    scanf("%d%d%d", &N, &E, &Q);
    dsu ds(MAXN);
    for(int i = 1; i <= E; i++){
        scanf("%d%d", &u, &v);
        if(ds.Union(u, v)){
            tree[u].push_back({v, i});
            tree[v].push_back({u, i});
        }
    }
    memset(parent, -1, sizeof(parent));
    preprocess(N);
    for(int i = 0; i < Q; i++){
        scanf("%d%d", &u, &v);
        if(!ds.sameComp(u, v)){
            printf("-1\n");
        }
        else{
            printf("%d\n", query(u, v));
        }
    }
    return 0;
}
