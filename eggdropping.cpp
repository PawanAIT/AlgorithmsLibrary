#include <bits/stdc++.h>
using namespace std;
const int N=1e3;
int dp[N][N];
int solve(int floor,int eggs)
{
	if(eggs==1)
		return floor;
	if(floor<=1)
		return floor;
	
	if(dp[floor][eggs])
		return dp[floor][eggs];
	dp[floor][eggs]=INT_MAX;
	for (int i = 1; i <=floor; ++i)
		dp[floor][eggs] = min(dp[floor][eggs],1+max(solve(i-1,eggs-1),solve(floor - i,eggs)));

	return dp[floor][eggs];
}
int main()
{
	int floor,eggs;
	cin>>floor>>eggs;
	memset(dp,0,sizeof(dp));
	solve(floor,eggs);
	printf("%d\n",dp[floor][eggs]);
	return 0;
}