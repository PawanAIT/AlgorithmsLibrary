#include "bits/stdc++.h"
#define ll long long int
using namespace std;
ll ST[400005];
ll Lazy[400005];
ll start,End,val;
ll N;
void update(ll l,ll h,ll i)
{
    
    if (Lazy[i])
    {
        ST[i]+=Lazy[i]*(h-l+1);
        if(l!=h)
        {
            Lazy[2*i+1]+=Lazy[i];
            Lazy[2*i+2]+=Lazy[i];  
        }
      
        Lazy[i]=0;
    }
    if (l>End||start>h)
    {
        return ;
    }
    if (start<=l && End>=h)
    {
        ST[i]+=(h-l+1)*val;
        if(l!=h)
        {
            Lazy[2*i+1]+=val;
            Lazy[2*i+2]+=val;
        }
        return ;
    }
 
    ll mid=(l+h)/2;
    update(l,mid,2*i+1);
    update(mid+1,h,2*i+2);
    ST[i]=ST[2*i+1]+ST[2*i+2];
}
 
    
ll query(ll l,ll h,ll i)
{
    if (l>End||start>h)
    {
        return 0;
    }
    if (Lazy[i])
    {
        ST[i]+=Lazy[i]*(h-l+1);
        if(l!=h)
        {
            Lazy[2*i+1]+=Lazy[i];
            Lazy[2*i+2]+=Lazy[i];  
        }
      
        Lazy[i]=0;
    }
    
       if (start<=l && End>=h)
       {
            return ST[i];
       }
 
       ll mid=(l+h)/2;
       return query(l,mid,2*i+1)+ query(mid+1,h,2*i+2);
      
}
int main()
{    
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll t,Q;
    cin>>t;
    while(t--)
    {
        memset(Lazy,0,sizeof(Lazy));
        memset(ST,0,sizeof(ST));
        cin>>N>>Q;
        while(Q--)
        {
            ll choice;
            cin>>choice;
            if (choice)
            {
                cin>>start>>End;
                start--,End--;
                cout<<query(0,N-1,0)<<endl;
            }
            else
            {
                cin>>start>>End>>val;
                start--,End--;
                update(0,N-1,0);
            }
        }
 
    }
    return 0;
    
} 
