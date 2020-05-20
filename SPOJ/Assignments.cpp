#include "bits/stdc++.h"
#define int ll
#define ll long long int
using namespace std;
int arr[30][30];
int dp[1<<22];
int mask;
int n;
const int mod=1000000007;
 
int bitmask(int mask)
{
    if (dp[mask]!=-1)
    {
        return dp[mask];
    }
    if (mask==0)
    {
        return 1;
    }
    int ans=0;
    dp[mask]=0;
    int x=__builtin_popcount(mask);
    for (int i = 0; i < n; ++i)
    {
        if (arr[x-1][i]&&((1<<(n-i-1))&mask))
        {
            //cout<<x<<" "<<n-i+1<<" "<<mask<<" "<<dp[mask]<<" \n";
            ans=(ans+bitmask((mask^(1<<(n-i-1)))));
 
        }
    }
    return dp[mask]=ans;
}
main()
{    
   // float x=clock();
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    //printf("%d\n",onebit(45));
    int fact[21]={1};
    for (int i = 1; i < 21; ++i)
    {
        fact[i]=fact[i-1]*i;
    }
    scanf("%lld",&t);
    while(t--)
    {
       
        memset(dp,-1,sizeof dp);
        int count=0;
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                scanf("%lld",&arr[i][j]);
                if(arr[i][j])
                count++;
            }
        }
        if (count==n*n)
        {
            printf("%lld\n",fact[n]);
            continue;
        }
        mask=(1<<n)-1;
        bitmask(mask);
        printf("%lld\n",dp[mask]);
        
    }
   // float end=clock();
   //cout<<(end-x);
 
     /**/
    return 0;
} 
