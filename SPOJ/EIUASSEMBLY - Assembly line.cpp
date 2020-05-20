#include<bits/stdc++.h>
#define ll long long int
using namespace std;
std::vector<pair<ll ,ll > > v;
ll  n,cost;
bool check(ll  mid)
{
   // cout<<mid<<endl;
    ll ans=0;
    for (ll  i = 0; i < v.size(); ++i)
    {
        if (v[i].first<mid)
        {
            if ((double)(mid-v[i].first)*(double)v[i].second > 1e12)
            {
               return 0;
            }
            ans+=(mid-v[i].first)*v[i].second;
            if (ans > 1e12)
            {
                return 0;
            }
        }
        if((double)ans>(double)cost)return 0;
    }
   // cout<<ans<<endl;
    if (ans <= cost)
        {
            return 1;
        }
        else
            return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    ll  t,q,r;
    cin>>t;
    while(t--)
    {
        ll ans=0;
        v.clear();
        cin>>n>>cost;
 
        for (ll  i = 0; i < n; ++i)
        {
            cin>>q>>r;
            v.push_back(make_pair(q,r));
        }
        /*if (cost==0)
        {
           for (int i = 0; i < v.size(); ++i)
           {
               cost=max(cost,v[i].first);
           }
           cout<<cost<<endl;
           continue;
        }*/
        ll low=0,high=1e18;
        while(low<high)
        {
            ll  mid=(low+high)/2;
            if (check(mid))
            {
                ans=max(ans,mid);
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
