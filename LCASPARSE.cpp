#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

vector<int> graph[MAXN];

// dfn helpers
int dfnIdx[MAXN], component[MAXN];
vector<pair<int, int>> mstack;
int numComponents;

// block-cut tree
vector<int> tree[2 * MAXN];
int depth[2 * MAXN];

// lca
int euler[4 * MAXN], eulerIdx;
int rmq[20][4 * MAXN];
int first[2 * MAXN];
int logarithm[4 * MAXN + 1];

void addComponent(const pair<int, int>& x) {
    bool flag = false;
    do {
        //cerr << numComponents << "' " << mstack.back().second << '\n';
        tree[numComponents + MAXN].push_back(mstack.back().second);
        tree[mstack.back().second].push_back(numComponents + MAXN);
        flag = mstack.back() == x;
        mstack.pop_back();
    } while (not flag);
    //cerr << numComponents << "' " << x.first << '\n';
    tree[numComponents + MAXN].push_back(x.first);
    tree[x.first].push_back(numComponents + MAXN);
    numComponents++;
}

int dfn(int node, int color) {
    static int nextIdx;
    int minPtr = dfnIdx[node] = nextIdx++;
    component[node] = color;
    for (const int& son: graph[node]) {
        if (dfnIdx[son] == -1) {
            mstack.push_back({node, son});
            int sonPtr = dfn(son, color);
            if (sonPtr >= dfnIdx[node]) {
                addComponent({node, son});
            } else if (sonPtr < minPtr) {
                minPtr = sonPtr;
            }
        } else if (dfnIdx[son] < minPtr) {
            minPtr = dfnIdx[son];
        }
    }
    return minPtr;
}

void dfs(int node, int parent) {
    first[node] = eulerIdx;
    euler[eulerIdx++] = node;
    for (const int& son: tree[node]) {
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
            } else {
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

bool intersect;
int ask(int a, int b, int c, int d) {
    if (depth[b] > depth[d]) {
        swap(a, c);
        swap(b, d);
    }

    int l = lca(a, c);

    if (depth[l] >= depth[d]) {
        intersect = true;
        return depth[l] - depth[d];
    }
    return 0;
}

bool query(int a, int b, int c) {
    if (component[b] != component[a] || component[c] != component[a]) {
        return false;
    }

    int l1 = lca(a, c), l2 = lca(b, c);
    intersect = false;
    return ask(a, l1, b, l2) + ask(a, l1, c, l2) + ask(c, l1, b, l2) + ask(c, l1, c, l2) + intersect <= 2;
}

int main() {

    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    memset(dfnIdx, -1, sizeof dfnIdx);
    memset(component, -1, sizeof component);
    for (int i = 0, color = 0; i < n; ++i) {
        if (component[i] != -1) {
            continue;
        }

        dfn(i, color++);
        dfs(i, -1);
    }

    assert(eulerIdx < 4 * MAXN);
    buildTable();

    while (q--> 0) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c--;
        cout << (query(a, b, c) ? "YES" : "NO") << '\n';
    }
}
