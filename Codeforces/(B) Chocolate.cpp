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
{
   int n,s=0;
   n=get();
   int a[102];
   for(int i=0;i<n;i++)
    {
        a[i]=get();
        if(a[i]==1)
            s=1;
    }
    if(s==0)
    {
        cout<<"0";
        return 0;
    }
    ll count=0,pro=1,flag=0;
   for(int i=0;i<n;i++)
   {
       if(a[i]==1)
        flag=1;
       if(flag==1)
       {
       if(a[i]==1)
        {
            pro=pro*(count+1);
            count=0;
        }

        if(a[i]==0)
            count++;
       }
   }

   cout<<pro;
}
