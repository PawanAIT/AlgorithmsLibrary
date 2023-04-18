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
    // freopen("test_input.txt", "r", stdin); // redirect input to "input.txt"
    // freopen("output.txt", "w", stdout); // redirect output to "output.txt"
    int N, E, Q;
    scanf("%d%d", &N, &E);
    vector<pair<int,int>> query, edges;
    auto input_graph = [&](){
        int u, v, type, dir;
        for (int i = 0; i < E; ++i) {
            scanf("%d%d", &u, &v);
            edges.push_back({u, v});
        }
        scanf("%d", &Q);
        for(int i = 0; i < Q; i++){
            scanf("%d", &type);
            if(type == 1){
                scanf("%d%d", &u, &dir);
                v = N + 1; N++;
                if(dir) swap(u, v);
                edges.push_back({u, v});
            }
            else{
                scanf("%d%d", &u, &v);
                query.push_back({u, v});
            }
        }
        VVI graph(N + 1);
        for(auto [u, v] : edges) graph[u].push_back(v);
        return graph;
    };
    VVI G = input_graph();
    Graph graph(G);
    auto CompGraph = graph.get_compressed_graph();
    Graph compressed_graph(CompGraph);
    auto processing_order = compressed_graph.get_topological_ordering();
    
    auto get_reach = [&](){
        VBitSet reach(compressed_graph.graph_size);
        for(auto u : processing_order) {  
            reach[u][u] = 1;
            for(auto v : compressed_graph.neighbours(u)){
                reach[u] |= reach[v];
            }
        }
        return reach;
    };
    auto reach = get_reach();
    for (auto [u, v] : query) {
        u = graph.component[u];
        v = graph.component[v];
        if(reach[u][v])
            printf("Yes\n");
        else       
            printf("No\n");
    }
   
    return 0;
}