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

using namespace std;
int main()
{    std::ios::sync_with_stdio(false);

  int arr[10]={0};
  arr[0]=6;
  arr[1]=2;
  arr[2]=5;
  arr[3]=5;
  arr[4]=4;
  arr[5]=5;
  arr[6]=6;
  arr[7]=3;
  arr[8]=7;
  arr[9]=6;
int a,b,t;
ll sum=0;
a=get(),b=get();
for (int i = a; i<=b; ++i)
{
    t=i;
    while(t)
       {
        sum+=arr[t%10];
        t=t/10;
       }

}
cout<<sum;
    return 0;
}
