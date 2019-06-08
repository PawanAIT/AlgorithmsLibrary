#include "bits/stdc++.h"
using namespace std;
const int N = 1000 + 5;
int dp[N][N];
class Solution {
public:
	int Knapsack(vector<int>& weight, vector<int>& values, int capacity) {
		memset(dp, 0, N * N);
		for (int i = 1; i <= weight.size(); i++) {
			for (int j = 1; j <= capacity; j++) {
				if (j >= weight[i - 1])
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + values[i - 1]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		return dp[weight.size()][capacity];
	}
};
int main() {

	int t;
	cin >> t;
	while (t--) {
		Solution solution;
		int n, capacity;
		cin >> n >> capacity;
		vector<int>	weight(n);
		vector<int>	values(n);
		for (auto& i : values)
			cin >> i;
		for (auto& i : weight)
			cin >> i;
		cout << solution.Knapsack(weight, values, capacity);
	}
	return 0;
}
