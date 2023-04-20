#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXLOG = 20;

vector<int> tree[MAXN];
int parent[MAXN][MAXLOG], depth[MAXN];

void dfs(int node, int par, int d = 1) {
    parent[node][0] = par;
    depth[node] = d;
    for (auto child : tree[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

void preprocess(int n) {
    memset(parent, -1, sizeof(parent));
    dfs(1, -1);

    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= n; j++) {
            if (parent[j][i - 1] != -1) {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
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

int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int N, Q, u, v;
    scanf("%d%d", &N, &Q);
    for(int i = 1; i < N; i++){
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    preprocess(N);
    for(int i = 0; i < Q; i++){
        scanf("%d%d", &u, &v);
        printf("%d\n", dist(u, v));
    }
    return 0;
}
