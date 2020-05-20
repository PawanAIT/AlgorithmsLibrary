#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{    
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        if (i%2==0)
        {
            cout<<"I hate ";
        }
        else
        {
            cout<<"I love ";
        }
        if (i==t-1)
        {
            cout<<"it";
        }
        else
            cout<<"that ";
    }

     
    return 0;
}
