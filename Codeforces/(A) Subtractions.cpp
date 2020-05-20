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

ll f(ll x,ll y)
{
	if (x%y!=0)
	{
		return (x/y +f(y,x%y));
	}
	else
		return x/y;
}

int main()
{	std::ios::sync_with_stdio(false);

	int t,x,y;
	t=get();
	while(t--)
	{
		
		x=get(),y=get();
		if (x>=y)
		{
			cout<<f(x,y)<<endl;
		}
		else
			cout<<f(y,x)<<endl;
		
		
	}
	return 0;
}
