#include <bits/stdc++.h>
using namespace std;
const int N=111;
int dp[N];
int solve(int n)
{
	if (n < 7)
		return n;
	if(dp[n])
		return dp[n];
	int ans=0;
	for(int breakpoint = n; breakpoint >= 1 ;breakpoint -- )
	{
		ans = max(ans,(n-breakpoint)*solve(breakpoint-1));
	}
	return dp[n]=ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		printf("%d\n",n>75?-1:solve(n));
	}
	return 0;
}