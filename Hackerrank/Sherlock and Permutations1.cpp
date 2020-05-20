#include<cstdio>
#define LL __int64
#include "bits/stdc++.h"

#define mod 1000000007
using namespace std;

int arr[2000][2000];

void precal()
{
	arr[0][0]=1;
	for (int i = 1; i <2000; ++i)
	{
		arr[i][0]=1;
		for (int j = 1; j<=i&&j<1001; ++j)
		{

			arr[i][j]=(arr[i-1][j]+arr[i-1][j-1])%mod;
		}
	}
}

int main(int argc, char const *argv[])
{
	precal();
	int t,m,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",arr[m+n-1][n]);

	}
	return 0;
}
