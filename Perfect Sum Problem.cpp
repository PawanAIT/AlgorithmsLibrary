#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dp[N][N],arr[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
			scanf("%d",&arr[i]);
		int sum=0;
		scanf("%d",&sum);
		memset(dp,0,sizeof(dp));
		for (int i = 0; i < N; ++i)
		{
			dp[i][0]=1;
		}
		for (int i = 1; i <=n; ++i)
		{
			for (int j = 1; j <=sum; ++j)
			{
				if (j-arr[i-1]>=0)
				{
					dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
				}
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		printf("%d\n",dp[n][sum]);
	}
	return 0;
}