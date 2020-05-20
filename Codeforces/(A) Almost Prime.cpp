#include "bits/stdc++.h"
#define ll __int64

using namespace std;
ll bb[25];
inline ll get(){ll c;ll n = 0;while ((c = getchar()) >= '0' && c <= '9')n = (n << 3) + ( n << 1 ) + c - '0';return n;}

inline void coutt(ll ans){if(!ans){putchar('0');return;}ll k = 0;while(ans){bb[k] = char((ans%10)+'0');++k;ans/=10;}for(int i=k-1;i>=0;--i)putchar(bb[i]);}

int main()
{	std::ios::sync_with_stdio(false);

	int t=1,count=0,arr[4000];
	t=get();
	for (int i = 2; i<=t; ++i)
	{
		if(!arr[i])
		for (int j= i+i; j<=t; j+=i)
		{
			arr[j]++;
		}
		
	}
	for (int i = 0; i <= t; ++i)
	{
		if (arr[i]==2)
		{
			count++;
		}
	}
	cout<<count;
	return 0;
}
