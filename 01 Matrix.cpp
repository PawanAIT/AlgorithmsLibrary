//https://leetcode.com/problems/01-matrix/
class Solution {
	int n, m;
	bool checkIfOut(int x, int y) {
		return x < 0 || y < 0 || y >= m || x >= n;
	}
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		queue<pair<int, int> > q;
		n = matrix.size();
		if (n > 0)
			m = matrix[0].size();
		vector<vector<int>> dp(n, vector<int>(m, INT_MAX / 10));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == 0) {
					q.push({ i, j });
					dp[i][j] = 0;
				}
			}
		}
		while (!q.empty()) {
			auto point = q.front();
			q.pop();
			int x = point.first;
			int y = point.second;
			if (!checkIfOut(x - 1, y) && dp[x][y] + 1 < dp[x - 1][y])
				dp[x - 1][y] = dp[x][y] + 1, q.push({ x - 1, y });
			if (!checkIfOut(x, y - 1) && dp[x][y] + 1 < dp[x][y - 1])
				dp[x][y - 1] = dp[x][y] + 1, q.push({ x, y - 1 });
			if (!checkIfOut(x + 1, y) && dp[x][y] + 1 < dp[x + 1][y])
				dp[x + 1][y] = dp[x][y] + 1, q.push({ x + 1, y });
			if (!checkIfOut(x, y + 1) && dp[x][y] + 1 < dp[x][y + 1])
				dp[x][y + 1] = dp[x][y] + 1, q.push({ x, y + 1 });
		}
		return dp;
	}
};