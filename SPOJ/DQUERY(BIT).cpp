#include "bits/stdc++.h"
#define ll __int64
using namespace std;
int BIT[1<<22];
int arr[1<<22];
int hash[1<<22];
int Query[1<<22];
int n;
struct node
{
    int first,second,idx;
}N[1<<22];
void update(int pos,int val)
{
    for(;pos<=2*n;pos+=pos&-pos)
    {
        BIT[pos]+=val;
    }
}
int sum(int pos)
{
    int res=0;
    for(;pos>0;pos-=pos&-pos)
    {
        res+=BIT[pos];
    }
    return res;
}
bool cmp(node &x,node &y)
{
    if (x.second!=y.second)
    {
       return x.second < y.second;
    }
    return x.first > y.first;
}
int main()
{    
    ios::sync_with_stdio(0); cin.tie(0);
    //int n;
    scanf("%d",&n);
    for (int i = 1; i <=n; ++i)
    {
        scanf("%d",arr+i);
    }
    int Q;
    scanf("%d",&Q);
    int l,r;
    for (int i = 0; i < Q; ++i)
    {
        scanf("%d%d",&l,&r);
        N[i].first=l,N[i].second=r;
        N[i].idx=i;
       // v.push_back(make_pair(l,r));
    }
    sort(N,N+Q,cmp);
    int j=1;
    //update(5,6);
   // cout<<sum(5);
    for (int i = 0; i < Q; ++i)
    {
         while(j <=N[i].second)
          {
                if (hash[arr[j]])
                {
                    update(hash[arr[j]],-1);
                }   
                update(j,1);
                hash[arr[j]]=j;
                ++j;
          }
          Query[N[i].idx]= sum(N[i].second)-sum(N[i].first-1);
    }
    for (int i = 0; i < Q; ++i)
    {
        printf("%d\n", Query[i]);
    }
    return 0;
}
