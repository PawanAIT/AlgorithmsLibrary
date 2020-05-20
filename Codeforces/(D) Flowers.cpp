#include "bits/stdc++.h"
#define ll __int64
using namespace std;
const ll mod=1000000007;
int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	int t,k;
	cin>>t>>k;
	ll dp[100005]={0};
	ll sum[100005]={0};
	dp[0]=1;
	for (int i = 0; i < 100005; ++i)
	{
		if (i-k>=0)
		{
			dp[i]=(dp[i-1]+dp[i-k]+mod)%mod;
		}
		else
			dp[i]=1;
	}
	for (int i = 1; i < 100005; ++i)
	{
		sum[i]=(sum[i-1]+dp[i-1]+mod)%mod;
	}
	
	int m,n;
	for (int i = 0; i < t; ++i)
	{
		cin>>m>>n;
		cout<<(sum[n+1]-sum[m]+mod)%mod<<endl;
	}
     
	return 0;
}
