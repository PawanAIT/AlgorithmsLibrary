#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{	/*believe me you can do this */
	ios::sync_with_stdio(0); cin.tie(0);
	int N=500005;
	int arr[500005]={0,1};
	for (int i = 2; i <500005 ; ++i)
	{
		if(!arr[i])
		for (int j = i; j < 500005; j+=i)
		{
			arr[j]=i; /*greatest prime factor*/
		}
	}
	for (int i = 2; i < 500005; ++i)
	{
		arr[i]=arr[i/arr[i]]+1;
	}

	int dp[500005]={0};
	for (int i = 1; i < 500005; ++i)
	{
		dp[i]=dp[i-1]+arr[i];
	}
	int t,x,y;
	cin>>t;

	for (int i = 0; i < t; ++i)
	{
		cin>>x>>y;
		cout<<dp[y]-dp[x];
	}

     
	return 0;
}