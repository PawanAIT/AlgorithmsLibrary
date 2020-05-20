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
int main()
{	std::ios::sync_with_stdio(false);

	int m,n,x,y;
	m=get(),n=get();
	std::vector<pair<ll,ll> > v(100000);
	for (int i = 0; i < m; ++i)
	{
		v[i].first=get();

	}
	for (int i = 0; i < m; ++i)
	{
		v[i].second=get();
	}
	ll ans1=0,ans2=0,k=0,z=0,f=0;
	
	for (int i = 0; i < m; ++i)
	{
		k+=v[i].second;
		ans1+=max(f,v[i].first-n*(k));
		z+=v[m-1-i].second;
		ans2+=max(f,v[m-1-i].first-n*(z));
	}

	//cout<<ans1<<" "<<ans2;
	if (ans1==ans2)
	{
		cout<<"Tie";
	}
	else if (ans1>ans2)
	{
		cout<<"Limak";
	}
	else
		cout<<"Radewoosh";

	return 0;
}
