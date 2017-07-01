#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dp[N][N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    scanf("%d",&dp[i][j]);

     for(int k=0;k<n;k++)
       for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
               
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                        printf("%d ",dp[i][j]);
            printf("\n");

    }
    return 0;
}