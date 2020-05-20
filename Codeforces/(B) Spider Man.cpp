#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{    
    ios::sync_with_stdio(0); cin.tie(0);
    ll t,q,sum=0;
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        cin>>q;
        sum+=q-1;
        if (sum%2)
        {
            cout<<1<<endl;
        }
        else
            cout<<2<<endl;
    }

     
    return 0;
}
