#include<cstdio>
#define LL __int64
#include "bits/stdc++.h"

#define mod 1000000007
using namespace std;

LL arr[300][300];

void precal()
{
	arr[0][0]=1;
	for (int i = 1; i <32; ++i)
	{
		arr[i][0]=1;
		for (int j = 1; j<=i; ++j)
		{

			arr[i][j]=(arr[i-1][j]+arr[i-1][j-1]);
		}
	}
}

int main(int argc, char const *argv[])
{
	precal();
	int t,m,n;
	scanf("%d%d%d",&t,&m,&n);

	LL sum=0;
	for (int i = 4; i <n; ++i)
	{
		
		sum+=(arr[t][i]*arr[m][n-i]);
	}

	printf("%I64d\n",sum);
	
	return 0;
}
