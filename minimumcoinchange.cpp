#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[2][N];
int cost[N],sum,n;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&sum);
		for (int i = 0; i < n; ++i)
			scanf("%d",&cost[i]);
		for (int i = 1; i < N; ++i)
			dp[0][i]=INT_MAX-500;
		
		for(int i=1;i<=n;i++)
		{
			for (int j = 1; j <=sum; ++j)
			{
				if (j-cost[i-1]>=0)
				{
					dp[i%2][j] = min(dp[(i+1)%2][j],1+dp[i%2][j-cost[i-1]]);
				}
				else
					dp[i%2][j] =  dp[(i+1)%2][j];
			}
		}
		printf("%d\n",dp[n%2][sum] > sum ? -1 :dp[n%2][sum]);
	}
	return 0;
}
/*
0 1 2 3
1 1 2 
2
3
*/
