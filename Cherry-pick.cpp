class Solution {
	int dp[55][55][55];
public:
    int cherryPickup(vector<vector<int>>& grid) {
		const int N = grid.size();	
        function<int(int, int,int)> dfs = [&](int x, int y, int x1){
			int y1 = x + y - x1;
			if(x < 0 || x >= N || y < 0 || y >= N || x1 <0 || x1 >= N || y1 < 0 || y1 >= N || grid[x][y] == -1 || grid[x1][y1] == -1)
				return INT_MIN / 10;
	
			int &ans = dp[x][y][x1];
	
			if(ans != -1)
				return ans;
	
			if(x == N - 1 && y == N - 1 && x == x1 && y == y1)
				return grid[x][y];
			
			ans = grid[x][y] + grid[x1][y1];
			if(x == x1 && y == y1)
				ans -= grid[x][y];

			int a = dfs(x + 1, y, x1 + 1); // DD
			int b = dfs(x, y + 1, x1); // RR
			int c = dfs(x + 1, y, x1); // DR
			int d = dfs(x, y + 1, x1 + 1); // RD

			return ans = ans + max({a,b,c,d});
		};
		memset(dp, -1, sizeof dp);
		return dfs(0,0,0) < 0 ? 0 : dfs(0,0,0);
    }
};
