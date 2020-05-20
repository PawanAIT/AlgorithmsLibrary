#include "bits/stdc++.h"
//#define ll __int64
using namespace std;
int BIT[1<<22];
struct node
{
    int L,R,val,idx,type;
}N[1<<22];
int Query[1<<22];
int n,Q;
int sum(int pos)
{
    int ans=0;
    for(;pos>0;pos-=pos&-pos)
    {
        ans+=BIT[pos];
    }
    return ans;
}
void update(int pos)
{
    for(;pos<=n+Q+100;pos+=pos&-pos)
    {
        BIT[pos]++;
    }
}
bool cmp(node &x,node &y)
{
    if (x.val!=y.val)
    {
        return x.val>y.val;
    }
    return x.type>y.type;
}
int main()
{    
    ios::sync_with_stdio(0); cin.tie(0);
    //int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&N[i].val);
        N[i].L=N[i].R=0;
        N[i].idx=i+1;
        N[i].type=0;
    }
    
    scanf("%d",&Q);
    for (int i = n; i < n+Q; ++i)
    {
        scanf("%d%d%d",&N[i].L,&N[i].R,&N[i].val);
        N[i].idx=i;
        N[i].type=1;
    }
    sort(N,N+Q+n,cmp);
    for (int i = 0; i < Q+n; ++i)
    {
        if (N[i].type==0)
        {
            update(N[i].idx);
        }
        else
        {
            Query[N[i].idx-n+1]=sum(N[i].R)-sum(N[i].L-1);
        }
    }
    for (int i = 1 ; i <=Q; ++i)
    {
        printf("%d\n",Query[i]);
    }

     
    return 0;
}
