#include "bits/stdc++.h"
using namespace std;
struct k
{
    int m;
    int n;
};
k mn[21];
bool acompare(k lhs, k rhs) { return lhs.n > rhs.n; }

int main(int argc, char const *argv[])
{
    int q,t;
    long long int ans=0;

    scanf("%d%d",&q,&t);
    
    for (int i = 0; i < t; ++i)
    {
        scanf("%d%d",&mn[i].m,&mn[i].n);
    }
    
    sort(mn, mn+t,acompare);

    for (int i = 0; i<t&&q>0; ++i)
    {
        if (q>=mn[i].m)
        {
            ans+=mn[i].m*mn[i].n;
            q=q-mn[i].m;
        }
        else
        {
            
            ans+=q*mn[i].n;
            q=q-mn[i].m;
        }
    }

    cout<<ans;
    return 0;
}
