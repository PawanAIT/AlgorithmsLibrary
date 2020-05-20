#include "bits/stdc++.h"
#define ll __int64
#define mod 10000
ll arr[1000][1000];
using namespace std;
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}


void pre()
{
    arr[0][0]=1;
for (int i = 1; i <800; ++i)
{
    arr[i][0]=1;
    for (int j = 1; j <10; ++j)
    {
        arr[i][j]=(arr[i-1][j-1]+arr[i-1][j]);
    }
}
}
int main(){
    pre();
   ll t,ans=1;
   t=get();
   cout<<arr[t][5]+arr[t][6]+arr[t][7];
}
