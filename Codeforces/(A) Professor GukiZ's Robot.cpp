#include "bits/stdc++.h"
#define ll __int64
using namespace std;
int main()
{    std::ios::sync_with_stdio(false);

    int a,b,c,d,n;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    cout<<max(abs(a-c),abs(b-d));
    return 0;
}
