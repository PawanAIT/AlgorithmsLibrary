#include "bits/stdc++.h"
#define ll __int64

using namespace std;
ll bb[25];
inline ll get(){ll c;ll n = 0;while ((c = getchar()) >= '0' && c <= '9')n = (n << 3) + ( n << 1 ) + c - '0';return n;}

inline void coutt(ll ans){if(!ans){putchar('0');return;}ll k = 0;while(ans){bb[k] = char((ans%10)+'0');++k;ans/=10;}for(int i=k-1;i>=0;--i)putchar(bb[i]);}

ll f(ll x,ll y)
{
	if(y==0)return 1;
	if(y%2==0){
		ll z=f(x,y/2);
		return z*z;
		}
		else
		return x*f(x,y-1); 
}
int main()
{	std::ios::sync_with_stdio(false);

	ll a,b,c;
	cin>>a>>b>>c;
	if (b==0)
	{
		putchar('0');return 0;
	}
	for (int i = -1000; i < 1001; ++i)
	{
		if (a*f(i,c)==b)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("No solution\n");
	return 0;
}
