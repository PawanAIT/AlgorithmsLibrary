#include "bits/stdc++.h"
#define ll long long int
using namespace std;
int arr[100005];
int t,m,n;
bool check(int mid)
{
    int count=0;
    for (int i = 0; i < n;)
    {
        int idx=lower_bound(arr+i+1,arr+n,arr[i]+mid)-arr;
      //  cout<<idx;
        if ( idx ==n )
        {
           return 0;
        }
        else
            count++;
        if (count==m-1)
        {
                return 1;
        }
        i=idx;
    }
    return 1;
}
int main()
{    
   // ios::sync_with_stdio(0); cin.tie(0);
    
    scanf("%d",&t);         
    while(t--)
    {
        ll ans=INT_MIN;
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",arr+i);
        }
        sort(arr,arr+n);
        ll l=0,r=1e10,mid;
       while(l<r)
        {
            mid=(l+r)/2;
            if (check(mid))
            {
                //cout<<mid<<" ";
                ans=max(ans,mid);
                l=mid+1;
            }
            else
            {
                r=mid;
            }
 
        }
            printf("%d\n", ans);
    }
 
 
     
    return 0;
} 
