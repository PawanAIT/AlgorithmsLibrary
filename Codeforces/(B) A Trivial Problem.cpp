#include "bits/stdc++.h"
#define ll __int64

using namespace std;
ll bb[25];
inline ll get(){ll c;ll n = 0;while ((c = getchar()) >= '0' && c <= '9')n = (n << 3) + ( n << 1 ) + c - '0';return n;}

inline void coutt(ll ans){if(!ans){putchar('0');return;}ll k = 0;while(ans){bb[k] = char((ans%10)+'0');++k;ans/=10;}for(int i=k-1;i>=0;--i)putchar(bb[i]);}

ll num(ll x)
{
    int count=0;
    for (int i = 5; x/i; i*=5)
    {
       count+=x/i;
    }
    return count;
}

int main()
{    std::ios::sync_with_stdio(false);


  int z;
  std::vector<int> v;

  cin>>z;
  for (int i = 0; i <=500000; ++i)
  {
    int y=num(i);
      if (y==z)
      {
        v.push_back(i);
      }
  }
  cout<<v.size()<<endl;
  for (int i = 0; i < v.size(); ++i)
  {
      cout<<v[i]<<" ";
  }
   return 0;
}
