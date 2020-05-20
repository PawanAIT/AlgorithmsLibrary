#include "bits/stdc++.h"
#define ll __int64
const int mod=pow(10,9)+7;
using namespace std;
int n,k,d;
int f(int n,int k)
{
	int ans[111]={1};
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 1; j <=k; ++j)
		{
			if(i-j>=0)
			ans[i]=(ans[i]+ans[i-j])%mod;
		}
	}
	return ans[n];
}
int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin>>n>>k>>d;
	cout<<(f(n,k)-f(n,d-1)+mod)%mod;
	return 0;
}
