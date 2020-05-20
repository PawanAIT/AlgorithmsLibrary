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

int main()
{    std::ios::sync_with_stdio(false);

    int t=1,n,k;
    ll sum=0,z;
  n=get(),k=get(),t=get();
  sum=n/3+k/3+t/3;
  if(n&&k&&t)
  {  
    z=(n-1)/3+(k-1)/3+(t-1)/3+1;
    sum=max(z,sum);
  }
   if(n&&k&&t)
   {
    z=(n-2)/3+(k-2)/3+(t-2)/3+2;
    sum=max(z,sum);
   }
cout<<sum;
        
    return 0;
}
