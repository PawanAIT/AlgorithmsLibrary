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
ll bb[25];
inline void coutt(ll ans)
{
    
    if(!ans){
        putchar('0');
        return;
    }
    ll k = 0;
    while(ans)
    {
        bb[k] = char((ans%10)+'0');
        ++k;
        ans/=10;
    }
    for(int i=k-1;i>=0;--i)
        putchar(bb[i]);
}
int main()
{    std::ios::sync_with_stdio(false);

    int t=1,n,arr[101],sum=0,count=0,max1=INT_MIN,temp;
        n=get();
        for (int i = 0; i < n; ++i)
        {
            arr[i]=get();
            if (arr[i]==1)
            {
                sum++;
            }
    
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {   temp=0;
                for (int k = i; k <=j; ++k)
                {
                    if (arr[k]==0)
                   { 
                      temp++;
                   }
                   else
                    temp--;
                }
                   
                max1=max(max1,temp);
            }
            
        }
        if(max1+sum<sum)
        {
            cout<<sum-1;
        }else cout<<max1+sum;
    
    return 0;
}
