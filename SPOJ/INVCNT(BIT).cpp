#include "bits/stdc++.h"
#define int ll
#define ll long long int
//#define ll __int64
using namespace std;
struct node
{
    int data,idx;
    bool operator <(node y)
    {
        return data < y.data ;
    }
}N[1<<22];
int BIT[1<<22];
int n;
void update(int pos)
{
    for(;pos<=n+100;pos+=pos&-pos)
    {
        BIT[pos]++;
    }
}
int sum(int pos)
{
    int ans=0;
    for(;pos>0;pos-=pos&-pos)
    {
        ans+=BIT[pos];
    }
    return ans;
}
main()
{    
    ios::sync_with_stdio(0); cin.tie(0);
     int t;
     scanf("%lld",&t);
     while(t--)
     {
        memset(BIT,0,sizeof BIT);
        scanf("%lld",&n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld",&N[i].data);
            N[i].idx=i+1;
        }
        sort(N,N+n);
        int ans=0;
        for (int i = n-1; i >=0; --i)
        {
            ans+=sum(N[i].idx);
            update(N[i].idx);
        }
        printf("%lld\n", ans);
     }
    return 0;
}
