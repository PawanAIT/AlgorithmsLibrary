#include "bits/stdc++.h"
#define ll __int64
using namespace std;
int arr[300005];
int main()
{    
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;

    for (int i = 0; i < t; ++i)
    {
        cin>>arr[i];
    }
    sort(arr,arr+t);
    if (t%2==0)
    {
        cout<<arr[t/2-1];
    }
    else
        cout<<arr[t/2];

     
    return 0;
}
