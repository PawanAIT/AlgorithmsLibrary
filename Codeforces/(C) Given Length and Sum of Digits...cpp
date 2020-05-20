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
{  std::ios::sync_with_stdio(false);
    clock_t start = clock();
    int m,n;
    cin>>m>>n;
    std::vector<int> v(101,0);
    std::vector<int> min(101,0);
    if (n==0&&m==1)
    {
        return 0 * printf("0 0\n");
    }
    if (n==0||9*m < n)
    {
      return 0*printf("-1 -1\n");
    }

    v[0]=n;
    for (int i = 0; i < m-1; ++i)
    {
      if (v[i]>9)
      { 
        v[i+1]=v[i]-9;
        v[i]=9;
      }
    }
    min=v;
    reverse(min.begin(),min.begin()+m);

    if (min[0]==0)
    {
      for (int i = 0; i < m; ++i)
      {
          if (min[i]>0)
          {
            min[i]--;
            break;
          }
      }
      min[0]=1;
    }
    for (int i = 0; i < m; ++i)
    {
        cout<<min[i];
    }
      cout<<" ";
    for (int i = 0; i < m; ++i)
    {
      cout<<v[i];
    }
    
    clock_t end = clock();
   // cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
  return 0;
}
