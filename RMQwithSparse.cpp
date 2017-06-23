#include "bits/stdc++.h"
#define ll __int64
using namespace std;
char str[2000+5];
char str2[2000+5];
int dp[2000+5][2000+5];
int min(int a,int b,int c)
{
	return min(a,min(b,c));
}
int main()
{	
	//ios::sync_with_stdio(0); cin.tie(0);
	int k;
	scanf("%s%s%d",1+str,1+str2,&k);
	int a=strlen(1+str);
	int b=strlen(1+str2);
	for (int i = 0; i <=max(a,b); ++i)
	{
		dp[i][0]=i*k;
		dp[0][i]=i*k;
	}
	for (int i = 1; i <=a; ++i)
	{
		for (int j = 1; j <=b; ++j)
		{
			dp[i][j]=min(dp[i-1][j]+k,dp[i][j-1]+k,dp[i-1][j-1]+abs(str[i]-str2[j]));
		}
	}
	printf("%d\n",dp[a][b]);

     
	return 0;
}