
 #include "bits/stdc++.h"
#define ll __int64
#define mod 10000
using namespace std;
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}

int main(){
   ll t,ans=1;
   t=get();
   cout<<t/2520;
}
