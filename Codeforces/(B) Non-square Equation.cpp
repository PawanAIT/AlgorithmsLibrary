#include "bits/stdc++.h"
#define ll __int64
using namespace std;
int sum(ll x)
{
    ll r=0;
    while(x)
    {
        r+=(x%10);
        x=x/10;
    }
    return r;
}
ll f(ll x)
{
    return x*x + sum(x)*x;
}
int main()
{    
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
   /* ll low=0,high=1e18;

    while(low<high)
    {
        ll mid=(low+high)/2;
        ll temp=f(mid);
        if (temp==n)
        {
            cout<<mid;
            return 0;
        }
        else if (temp<n)
        {
            low=mid;
        }
        else if (temp>n)
        {
             high=mid;
        }
           
    }

     cout<<-1;*/
    ll ans=sqrt(n);
   // cout<<ans;
    int count=0;
    while(ans)
    {
        ll temp=f(ans);
        if (temp<n)
        {
            count++;
            if (count>1000)
            {
                break;
            }
        }
        if (temp==n)
        {
                cout<<ans;
                return 0;
        }
        ans--;
    }
    cout<<-1;
    return 0;
}
