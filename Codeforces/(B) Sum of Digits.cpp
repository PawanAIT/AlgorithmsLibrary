#include "bits/stdc++.h"
#define ll __int64
using namespace std;
inline ll get()
{
    ll c,i=0;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
         { n += c - '0';i++;}
    
    return i==1?0:n;
}

int t(int x)
{
    if (x==0)
    {
        return 0;
    }
    if (x<10)
        return 1;
    
    int w=0,k=0;
    while(x){
        w=w+x%10;
        x=x/10;
    }
    return 1+t(w); 
}

int main()
{    std::ios::sync_with_stdio(false);

    ll x;
    x=get();

        cout<<t(x);
   
    return 0;
}
