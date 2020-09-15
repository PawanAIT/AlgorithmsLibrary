class Solution {
public:
	int numWays(int step, int arrLen) {

		int dp[505][505];
		const int mod = 1e9 + 7;
		memset(dp, -1, sizeof dp);
		function<int(int, int)> dfs = [&](int steps, int pos) {
			if (pos < 0 || pos >= arrLen)
				return 0;
			if (steps == step) {
				if (pos == 0)
					return 1;
				return 0;
			}
			int &ans = dp[steps][pos];

			if (ans != -1)
				return ans;

			long int left = dfs(steps + 1, pos - 1);
			long int right = dfs(steps + 1, pos + 1);
			long int stay = dfs(steps + 1, pos);
			return ans = (left + right + stay) % mod;
		};
		return dfs(0, 0);
	}
};