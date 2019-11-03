class Solution {
const long long M = 1e9 + 7;
long long dp[1000 + 5];
int n;
int solve(int idx){
    if(idx == n + 1)
        return 1;
    if(idx > n + 1)
        return 0;
    if(dp[idx] != -1)
        return dp[idx];
    long long ans = 0;
    ans += solve(idx + 1);
    ans += solve(idx + 2);
    for(int i = 0 ; i <= n ; i++){
        int j = 3 + i * 2;
        int k = 4 + i * 2;
        ans += 2 * solve(idx + j);
        ans += 2 * solve(idx + k);
    }
    ans %= M;
    return dp[idx] = ans;
}
public:
    int numTilings(int N) {
        n = N;
        memset(dp , -1, sizeof(dp));
        return solve(1);
    }
};
