#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<int,int>arr,arr1;
  map<pair<int,int>,int>zx;
 int n,x,y;
 cin>>n;
 for(int i=0;i<n;i++)
 {
     cin>>x>>y;
     arr[x]++,arr1[y]++;
     zx[make_pair(x,y)]++;
 }
 long long sum=0;
  map<int,int>::iterator it;
  for(it=arr.begin();it!=arr.end();it++)
  {
      if(it->second>0)
      {
         long long  z=it->second;
      sum+=(z)*(z-1)/2;
      }
  }
   for(it=arr1.begin();it!=arr1.end();it++)
  {
      if(it->second>0)
      {
       long long  z=it->second;
      sum+=(z)*(z-1)/2;
      }
  }
 // cout<<sum;
  map<pair<int,int>,int> ::iterator xq;
  for(xq=zx.begin();xq!=zx.end();xq++)
  if((xq->second)>0)
  sum-=(long long)(xq->second)*(xq->second-1)/2;
  
  cout<<sum;
    return 0;
}
