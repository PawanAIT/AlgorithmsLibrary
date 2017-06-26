#include <bits/stdc++.h>
using namespace std;

vector<long long> factor(long long x)
{
  vector<long long> res;
  long long i=2;
  while(i*i<=x)
  {
    while(x%i==0)
    {
      res.push_back(i);
      x=x/i;
    }
    i++;
  }
  if (x!=1)
  res.push_back(x);
  return res;
}
int main()
{

    long long t;
    scanf("%lld",&t);
    while(t--)
    {
      long long n;
      scanf("%lld",&n);
      if(n==1)
        {puts("1");continue;}
      vector<long long> v=factor(n);
      sort(v.begin(),v.end());
      long long ans=0;
      for (long long i = 0; i < v.size(); ++i)
      {
        auto hi=upper_bound(v.begin(), v.end(),v[i]);
        auto low=lower_bound(v.begin(), v.end(),v[i]);
        long long hehe=(hi-low);
        ans=max(ans,(long long)v[i]*hehe);
      }
      printf("%lld\n",ans);
    }

    return 0;
}