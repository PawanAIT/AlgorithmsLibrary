#include "bits/stdc++.h"
#define ll __int64

using namespace std;
ll bb[25];
inline ll get(){ll c;ll n = 0;while ((c = getchar()) >= '0' && c <= '9')n = (n << 3) + ( n << 1 ) + c - '0';return n;}

inline void coutt(ll ans){if(!ans){putchar('0');return;}ll k = 0;while(ans){bb[k] = char((ans%10)+'0');++k;ans/=10;}for(int i=k-1;i>=0;--i)putchar(bb[i]);}


int f(int a,int b)
{
    if (a<=0||b<=0)
    {
        return 0;
    }
    if (a>b)
    {
       return 1+f(a-2,b+1);
    }
    else
        return 1+f(a+1,b-2);
}
int main()
{    std::ios::sync_with_stdio(false);

    int t=1,m,n;
    m=get(),n=get();
    if(m==1&&n==1)cout<<0;
    else
        cout<<f(m,n);
    
    return 0;
}
