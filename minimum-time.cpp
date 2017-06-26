//http://practice.geeksforgeeks.org/problems/minimum-time/0
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int dp[101];
		fill(dp,dp+101,INT_MAX-100000);
		int n,del,copy,insert;
		scanf("%d",&n);
		scanf("%d%d%d",&insert,&del,&copy);
		dp[0]=0;
		for (int i = 1; i <=n; ++i)
		{
			if (i%2==0)
			{
				dp[i]=min(dp[i-1]+insert,dp[i/2]+copy);
			}
			else
				dp[i]=min(dp[i-1]+insert,dp[(i+1)/2]+copy+del);
		}
		printf("%d\n",dp[n]);
	}
	
	return 0;
}