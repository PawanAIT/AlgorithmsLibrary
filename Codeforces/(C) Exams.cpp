#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{  
  ios::sync_with_stdio(0); cin.tie(0);
  std::vector<pair<int,int> > v;
  int t,m,n;
  cin>>t;
  for (int i = 0; i < t; ++i)
  {
    cin>>m>>n;
    v.push_back(make_pair(m,n));
  }
  sort(v.begin(),v.end());
  int ans=0;
  for (int i = 0; i < t; ++i)
  {
    if (ans<=v[i].second)
    {
      ans=v[i].second;
    }
    else
      ans=v[i].first;
  }
cout<<ans;

     
  return 0;
}
