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
    clock_t start = clock();
    int m,n;
    cin>>m>>n;
    ll sum=0,x,count=0;
    char ch;
    sum=n;
    for (int i = 0; i < m; ++i)
    {
        cin>>ch>>x;
        if (ch=='-'&&sum-x>=0)
        {
            sum=sum-x;
        }
        else if(ch=='+')
        {
             sum=sum+x;
        }
        else
            count++;
    }
    cout<<sum<<" "<<count;
    clock_t end = clock();
  //  cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    return 0;
}
