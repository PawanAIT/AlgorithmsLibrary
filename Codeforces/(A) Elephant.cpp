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

    int t=1,arr[100000],n;
    t=get();
    if (t%5==0)
    {
     cout<<t/5;
    }
    else
    cout<<t/5+1;
    return 0;
}
