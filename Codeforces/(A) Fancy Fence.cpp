#include "bits/stdc++.h"
#define ll long long int
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

    int t=1,n;
    std::vector<float> v;
    for (int i = 3; i < 362; ++i)
    v.push_back(1.0f*(i-2)*180/i);
        n=get();
        for (int i = 0; i < n; ++i)
        {
            t=get();
            binary_search(v.begin(),v.end(),t)?puts("YES"):puts("NO");
        }

    return 0;
}
