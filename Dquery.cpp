#include "bits/stdc++.h"
#define ll __int64
using namespace std;
int k;
char str[100+5],str1[100+5];
int dp[100+5][100+5];
int ThreeD[101][101][101];
int solve(int i,int j,int k)
{
	int ans=0,ans2=0,ans3=0;
	if (k==0)
	{
		return 0;
	}
	if (i<0||j<0)
	{
		return -1;
	}
	if (ThreeD[i][j][k]!=-1)
	{
		return ThreeD[i][j][k];
	}

	if (str[i]==str1[j])
	{
		//printf("yeah");
		//printf("%c\n",str[i]);
		ans=solve(i-1,j-1,k-1);
		if (ans!=-1)
		{
			ans+=str[i];
		}
	}
	else
	{
		ans2=solve(i,j-1,k);
		ans3=solve(i-1,j,k);
		
	}
	return ThreeD[i][j][k]=max(ans,max(ans3,ans2));
	//return max(ans,ans2);
}
int main()
{	
	//ios::sync_with_stdio(0); cin.tie(0);
	int t;
	scanf("%d",&t);
	while(t--)
	{

		memset(dp,0,sizeof dp);
		memset(ThreeD,-1,sizeof ThreeD);
		scanf("%s%s%d",str,str1,&k);
		int K=k;
		/*fflush(stdin);
		scanf("%s",str1);
		fflush(stdin);
		scanf("%d",&k);
		printf("%s====%s===%d\n",str,str1,k);*/
		int a=strlen(str);
		int b=strlen(str1);
		
		for (int i = 0; i <=a; ++i)
		{
			for (int j = 0; j <=b; ++j)
			{
				if (i==0||j==0)
				{
					dp[i][j]=0;
				}
				else if(str[i-1]==str1[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		//printf("%d\n",dp[a][b]);
		if (K>dp[a][b])
		{
			printf("%d\n",0);
		}
		else
		{
			//printf("LOL");
			int ans=solve(a-1,b-1,k);
			printf("%d\n",ans);
		}
	}
	return 0;
}
