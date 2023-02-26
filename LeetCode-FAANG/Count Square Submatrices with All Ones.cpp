class Solution {
private:
	vector<vector<int> > dp;
public:
	int countSquares(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return 0;
		int n = matrix.size();
		int m = matrix[0].size();
		dp.resize(n + 1, vector<int>(m + 1));
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (matrix[i - 1][j -  1] == 1) {
					dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
					ans += dp[i][j];
				}
			}
		}
		return ans;
	}
};