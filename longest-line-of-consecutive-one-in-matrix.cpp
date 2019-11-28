// Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
// Example:
// Input:
// [[0,1,1,0],
//  [0,1,1,0],
//  [0,0,0,1]]
// Output: 3
// Hint: The number of elements in the given matrix will not exceed 10,000.

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size();
        int maxl = 0, hori = 0, vert = 0, inc = 0, desc = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0, hori = 0; j < n; j++, maxl = max(maxl, hori))
                hori = M[i][j] ? hori + 1 : 0;

        for (int j = 0; j < n; j++)
            for (int i = 0, vert = 0; i < m; i++, maxl = max(maxl, vert))
                vert = M[i][j] ? vert + 1 : 0;

        for (int k = 0; k < m + n; k++) {
            for (int i = min(k, m - 1), j = max(0, k - m), inc = 0; i >= 0 && j < n; i--, j++, maxl = max(maxl, inc))
                inc = M[i][j] ? inc + 1 : 0;
            for (int i = max(m - 1 - k, 0), j = max(0, k - m), desc = 0; i < m && j < n; i++, j++, maxl = max(maxl, desc))
                desc = M[i][j] ? desc + 1 : 0;
        }
        return maxl;
    }
};

public int longestLine(int[][] M) {
    int n = M.length, max = 0;
    if (n == 0) return max;
    int m = M[0].length;
    int[][][] dp = new int[n][m][4];
    for (int i=0;i<n;i++) 
        for (int j=0;j<m;j++) {
            if (M[i][j] == 0) continue;
            for (int k=0;k<4;k++) dp[i][j][k] = 1;
            if (j > 0) dp[i][j][0] += dp[i][j-1][0]; // horizontal line
            if (j > 0 && i > 0) dp[i][j][1] += dp[i-1][j-1][1]; // anti-diagonal line
            if (i > 0) dp[i][j][2] += dp[i-1][j][2]; // vertical line
            if (j < m-1 && i > 0) dp[i][j][3] += dp[i-1][j+1][3]; // diagonal line
            max = Math.max(max, Math.max(dp[i][j][0], dp[i][j][1]));
            max = Math.max(max, Math.max(dp[i][j][2], dp[i][j][3]));
        }
    return max;
}
Note that each cell of the DP table only depends on the current row or previous row so you can easily optimize the above algorithm to use only O(m) space.