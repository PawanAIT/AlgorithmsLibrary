// You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

// Each 0 marks an empty land which you can pass by freely.
// Each 1 marks a building which you cannot pass through.
// Each 2 marks an obstacle which you cannot pass through.
// Example:

// Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

// 1 - 0 - 2 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0

// Output: 7 

// Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
//              the point (1,2) is an ideal empty land to build a house, as the total 
//              travel distance of 3+3+1=7 is minimal. So return 7.
// Note:
// There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

I also tested the other three C++ solutions posted so far, they took 340-1812 ms. I think mine is faster because I don't use a fresh "visited" for each BFS. Instead, I walk only onto the cells that were reachable from all previous buildings. From the first building I only walk onto cells where grid is 0, and make them -1. From the second building I only walk onto cells where grid is -1, and I make them -2. And so on.

int shortestDistance(vector<vector<int>> grid) {
    int m = grid.size(), n = grid[0].size();
    auto total = grid;
    int walk = 0, mindist, delta[] = {0, 1, 0, -1, 0};
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (grid[i][j] == 1) {
                mindist = -1;
                auto dist = grid;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (q.size()) {
                    auto ij = q.front();
                    q.pop();
                    for (int d=0; d<4; ++d) {
                        int i = ij.first + delta[d];
                        int j = ij.second + delta[d+1];
                        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                            grid[i][j]--;
                            dist[i][j] = dist[ij.first][ij.second] + 1;
                            total[i][j] += dist[i][j] - 1;
                            q.emplace(i, j);
                            if (mindist < 0 || mindist > total[i][j])
                                mindist = total[i][j];
                        }
                    }
                }
                walk--;
            }
        }
    }
    return mindist;
}