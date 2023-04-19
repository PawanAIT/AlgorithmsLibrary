#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5e4 + 5;
using VI = vector<int> ;
using VVI = vector<VI >;
using VBitSet = vector<bitset<MAXN> >;
class Graph{
    VVI graph;
    VVI rev_graph;
    public:
    int graph_size;
    VI topological_order;
    VI component;
    Graph(VVI &graph) : graph(graph), graph_size(graph.size()) {}

    VVI get_reverse_graph() {
        VVI rev_graph(graph_size);
        for (int u = 1; u < graph_size; u++) {
            for (auto &v : graph[u]) {
                rev_graph[v].push_back(u);
            }
        }
        return rev_graph;
    };
    VI get_topological_ordering(){
        vector<bool> vis(graph_size);
        VI st;
        function<void(int)> topological_sort = [&](int u){
            if(vis[u]) return;
            vis[u] = true;
            for(auto v : graph[u]){
                topological_sort(v);
            }
            st.push_back(u);
        };
        for(int u = 1; u < graph_size; u++){
            if(!vis[u])
                topological_sort(u);
        }
        return st;
    };
    VVI get_compressed_graph(){
        rev_graph = get_reverse_graph();
        topological_order = get_topological_ordering();
        reverse(topological_order.begin(), topological_order.end());
        int compressed_graph_size = get_components(topological_order);
        VVI compressed_graph(compressed_graph_size);
        for(int u = 1; u < (int)graph.size(); u++){
            for(auto &v : graph[u]){
                int x = component[u];
                int y = component[v];
                if(x != y){
                    compressed_graph[x].push_back(y);
                }
            }
        }
        return compressed_graph;
    }
    VI neighbours(int u){
        return graph[u];
    }
    private:
    int get_components(VI &processing_order){
        component.resize(graph_size);
        function<void(int, int)> colour_scc = [&](int u, int col){
            if(component[u]) return;
            component[u] = col;
            for(auto &v : rev_graph[u]){
                colour_scc(v, col);
            }
        };
        int compId = 1;
        for(auto u : processing_order){
            if(!component[u])
                colour_scc(u, compId++);
        }
        return compId;
    };
};
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int N, E;
    scanf("%d%d", &N, &E);
    auto input_graph = [&](){
        VVI graph(N + 1);
        int u, v;
        for (int i = 0; i < E; ++i) {
            scanf("%d%d", &u, &v);
            graph[u].push_back(v);
        }
        return graph;
    };
    VVI G = input_graph();
    Graph graph(G);
    auto processing_order = graph.get_topological_ordering();

    auto get_reach = [&](){
        VBitSet reach(graph.graph_size);
        for(auto u : processing_order) {
            reach[u][u] = 1;
            for(auto v : graph.neighbours(u)){
                reach[u] |= reach[v];
            }
        }
        return reach;
    };
    auto reach = get_reach();

    for(int i = 1; i < graph.graph_size; i++){
        printf("%d ", (int)reach[i].count());
    }
    return 0;
}
