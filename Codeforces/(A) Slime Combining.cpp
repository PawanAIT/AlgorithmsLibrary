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
    
    ll t;
    t=get();
    int arr[10000];
    for (int i = 0; i < 10000; ++i)
    {
        arr[i]=1;
    }
    int k=0,i=0,sum=0;
   
    for (int j=0;j!=t;j++)
    {     
        while(i>0&&arr[i]==arr[i-1])
        {
            arr[i-1]=arr[i-1]+1;
            arr[i]=1;
            i--;
        }
        i++;
    }
    for (int j = 0; j < i; ++j)
    {
       cout<<arr[j]<<" ";
    }
    return 0;
}
