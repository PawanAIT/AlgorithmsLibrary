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
{   std::ios::sync_with_stdio(false);

    int m,n,min=INT_MAX,max=INT_MIN,x;
    m=get();n=get();
        for (int i = 0; i < m; ++i)
        {
            min=INT_MAX;
            for (int j = 0; j < n; ++j)
            {
                x=get();
                if (x<min)
                {
                    min=x;
                }
            }
            if (max<min)
            {
                max=min;
            }
        }

        printf("%d\n", max);
    return 0;
}
