// Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
// The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
// Note: You can only put the bomb at an empty cell.

// Example:

// Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
// Output: 3 
// Explanation: For the given grid,

// 0 E 0 0 
// E 0 W E 
// 0 E 0 0

// Placing a bomb at (1,1) kills 3 enemies.

public class Solution {
    public int maxKilledEnemies(char[][] grid) {
        if(grid== null || grid.length == 0 || grid[0].length==0) return 0; 
        int rows = grid.length; 
        int cols = grid[0].length; 
        int max = 0; 
        int[][] dp = new int[rows][cols];
        //travel each column twice: from left and from right
        for(int i = 0; i<rows; i++){
            int cnt = 0; 
            for(int k = 0; k<cols; k++){
                if(grid[i][k]=='0'){
                    dp[i][k] = cnt; 
                }else if(grid[i][k]=='E'){
                    cnt++;
                }else{
                    cnt = 0; 
                }
            }
            cnt = 0; 
            for(int k = cols-1; k>=0; k--){
                if(grid[i][k]=='0'){
                    dp[i][k] += cnt; 
                }else if(grid[i][k]=='E'){
                    cnt++;
                }else{
                    cnt = 0;
                }
            }
        }
        //travel each row twice: from top and from bottom
        for(int i = 0; i<cols; i++){
            int cnt = 0; 
            for(int k = 0; k<rows; k++){
                if(grid[k][i]=='0'){
                    dp[k][i] += cnt; 
                }else if(grid[k][i]=='E'){
                    cnt++;
                }else{
                    cnt = 0; 
                }
            }
            cnt = 0; 
            for(int k = rows-1; k>=0; k--){
                if(grid[k][i]=='0'){
                    dp[k][i] += cnt; 
                    max = Math.max(max, dp[k][i]); 
                }else if(grid[k][i]=='E'){
                    cnt++;
                }else{
                    cnt = 0;
                }
            }
        }
        return max; 
    }
}