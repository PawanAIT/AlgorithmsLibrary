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

   char arr[105][105];
   ll sum=0;
   int t=get();
   for (int i = 0; i < t; ++i)
   {
       scanf("%s",arr[i]);
   }
int count=0,count2=0;
   for (int i = 0; i < t; ++i)
   {
    count=0,count2=0;
       for (int j = 0; j < t; ++j)
       {
           if (arr[i][j]=='C')
           {
               count++;
           }
           if (arr[j][i]=='C')
           {
              count2++;
           }
       }
       sum+=count*(count-1)/2+count2*(count2-1)/2;
   }
   coutt(sum);
    return 0;
}
