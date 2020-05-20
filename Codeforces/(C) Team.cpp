#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{  
  ios::sync_with_stdio(0); cin.tie(0);
  int m,n;
  cin>>n>>m;
  if (n>m+1 || m > 2*n+2)
  {
    return 0*puts("-1");
  }
  while(m>0&&n>0&&m>n)
  {
      printf("110");
      m=m-2; n--;  
  }
  if (n>m)
  {
    printf("0");
    n--;
  }
  while(m&&n)
  {
    printf("10");
    m--;
    n--;
  }
  while(m--)printf("1");




}
