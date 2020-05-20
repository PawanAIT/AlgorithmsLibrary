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
{//	std::ios::sync_with_stdio(false);

	int arr[100005],k;
	ll t=1,n,m;
	k=get();
	n=get();
	for (int i = 0; i < k; ++i)
	{
		cin>>arr[i];
	}
	m=floor((-1+sqrt(8*n-7))/2);
int ans=n-m*(m+1)/2;
cout<<arr[ans-1];
	return 0;
}
