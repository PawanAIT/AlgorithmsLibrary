#include "bits/stdc++.h"
#define ll __int64
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a;
    ll dp[100005]={0};
    int cnt[100005];
    cin>>n;
    
    for( int i = 0 ; i < n ; i++ )
    {
         cin>>a;     
         cnt[a]++;    
    }

    dp[1] = cnt[1];

    for( int i = 2 ; i <= 100000 ; i++ )
         dp[i] = max( dp[i-1] , (dp[i-2] + (ll)(i*(ll)cnt[i])) ); 

    cout<<dp[100000];
    return 0;
        
}
