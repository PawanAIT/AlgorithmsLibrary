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
{    std::ios::sync_with_stdio(false);

    int t=1,n,sum=0,count=0,arr[100005];
    t=get();
    
        for (int i = 0; i < t; ++i)
        {
            arr[i]=get();
        }
    sort(arr,arr+t);
    for (int i = 0; i < t; ++i)
    {
       if (sum>arr[i])
       {    
            count++;
       }
       else
        sum+=arr[i];

    }
    cout<<t-count;
    return 0;
}
