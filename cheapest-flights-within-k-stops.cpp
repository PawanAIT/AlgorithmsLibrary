#include <bits/stdc++.h>
using namespace std;

class Solution {
	struct node {
		int source, val, jump;
		bool operator <(const node &y) const {
			return this->val > y.val;
		}
	};
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int> > graph[101];
        for(auto edge : flights){
            int u, v, w;
            u = edge[0];
            v = edge[1];
            w = edge[2];
            graph[u].push_back({v, w});
        }
		priority_queue<node> pq;
		pq.push(node({src, 0, K + 1}));
        while (!pq.empty()) {
            auto [source, val, jump] = pq.top();
            pq.pop();
            if(source == dst)
                return val;
            if(jump == 0)
                continue;
            int u = source;
            for(auto val : graph[source]){
                auto [v, w] = val;
                pq.push(node({v, w + val, K - 1}));
            }
        }
        return -1;
    }
};
int main(){
    cout << "hellow\n";
    return 0;
}