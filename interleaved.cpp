
bool isInterleave(string A, string B, string C) 
{
    int a = A.size();
    int b = B.size();
    int c = C.size();
    int dp[a + 1][b + 1] ;
    memset(dp , 0 , sizeof(dp));
    for(int i = 0 ; i <= a ; i++){
        for(int j = 0 ; j <= b ; j++){
            if(i == 0 and j == 0){
                dp[i][j] = true;
            }
            else if(i == 0 and B[j - 1] == C[j - 1]){
                dp[i][j] = dp[i][j - 1];
            }
            else if(j == 0 and A[i - 1] == C[i - 1]){
                dp[i][j] = dp[i - 1][j];
            }
            if(A[i - 1] == C[i + j - 1])
                dp[i][j] |= dp[i - 1][j];
            if(B[j - 1] == C[i + j -1])
                dp[i][j] |= dp[i][j - 1];
        }
        
    }
    return dp[a][b];
}
