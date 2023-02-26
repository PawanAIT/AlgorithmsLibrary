class Solution {
public:
	int countServers(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;
		int rowCount = grid.size();
		int colCount = grid[0].size();
		vector<int> row(rowCount), col(colCount);
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				if (grid[i][j])
					row[i]++, col[j]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < colCount; j++) {
				if (grid[i][j] and (row[i] > 1 or col[j] > 1))
					ans++;
			}
		}
		return ans;
	}
};