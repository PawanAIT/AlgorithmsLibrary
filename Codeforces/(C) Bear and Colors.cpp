#include "bits/stdc++.h"
#define ll __int64
using namespace std;
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}
ll bb[25];
inline void coutt(ll ans)
{
    
    if(!ans){
        putchar('0');
        return;
    }
    ll k = 0;
    while(ans)
    {
        bb[k] = char((ans%10)+'0');
        ++k;
        ans/=10;
    }
    for(int i=k-1;i>=0;--i)
        putchar(bb[i]);
}
int dp[5005][5005];
int main()
{
     ios_base::sync_with_stdio(0);
	int n;
	n=get();
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		v.push_back(get());
	}
	for (int i = 1; i < n+1; ++i)
	{
		int arr[5005]={0};
		for (int j = i; j < n+1; ++j)
		{
			arr[v[j-1]]++;
			if (arr[dp[i][j-1]]>arr[v[j-1]])
			{
				dp[i][j]=dp[i][j-1];
			}
			else if (arr[dp[i][j-1]]<arr[v[j-1]])
			{
				dp[i][j]=v[j-1];
			}
			else
			{
				dp[i][j]=min(dp[i][j-1],v[j-1]);
			}
		}
	}
	int arr[5005]={0};
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = i; j < n+1; ++j)
		{
			arr[dp[i][j]]++;
		}
		
	}
	for (int i = 1; i <=n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
