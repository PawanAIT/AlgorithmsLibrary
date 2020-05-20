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

	int ans=0;
	int n;
	cin>>n;
	ans=(n/7)*2;
	if(n%7==0)
	{	cout<<ans<<" "<<ans;
       return 0;
   }
   if (n%7==1)
   {
   	cout<<ans<<" "<<ans+1;
   	return 0;

   }
   if (n%7==6)
   {
   	cout<<ans+1<<" "<<ans+2;
   }
   else 
   {
   	cout<<ans<<" "<<ans+2;
   	return 0;
   }

	return 0;
}
