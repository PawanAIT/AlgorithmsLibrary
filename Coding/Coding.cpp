#include <cstddef>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int dp[500];
	int dfs(int n) {
		if (n == 0)
			return 1;
		if (dp[n]) {
			return dp[n];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += dfs(i - 1) * dfs(n - i);
		}
		return dp[n] = ans;
	}
	int numTrees(int n) {
		return dfs(n);
	}
};