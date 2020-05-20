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

	int m,n,k;
	std::vector<int> arr;
	m=get(),n=get(),k=get();
	for (int i = 0; i < m; ++i)
	{
		arr.push_back(get());
	}
	ll x=0;
	ll ans=0;
	for (int i = 0; i<m ;)
	{
		if (x + arr[i] > n)
		{
			//cout<<"hello\n";
			if (k>x)
			{
				ans++;
				x=0;
			}
			ans+=x/k;
			x=x%k;
		}
		else{
			//cout<<"H\n";
			x=x+arr[i];
			i++;
		}
	}
	ans+=x/k+(x%k>0);
	cout<<ans;
	return 0;
}
