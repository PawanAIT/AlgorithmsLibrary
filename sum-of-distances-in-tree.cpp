class Solution {
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		vector<int> down(N), count(N + 1); // do we need it ?! [Check]
		vector<int> graph[N];
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}
		function<void(int, int)> dfsdown = [&](int u, int p) {
            count[u] = 1;
			for (auto v : graph[u]) {
				if (v != p) {
					dfsdown(v, u);
					count[u] += count[v];
					down[u] += count[v] + down[v];
				}
			}
		};
		function<void(int, int)> dfsup = [&](int u, int p) {
			for (auto v : graph[u]) {
				if (v != p) {
					down[v] = down[u] - count[v] + N - count[v];
					dfsup(v, u);
				}
			}
		};
		dfsdown(0, -1);
		dfsup(0, -1);
		return down;
	}
};