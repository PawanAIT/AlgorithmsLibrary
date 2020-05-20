#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{    
    freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

    // see this video for more info https://www.youtube.com/watch?v=TWHytKnOPaQ
   // ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int arr[100005];

    int left[100005]={0},right[100005]={0};
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
        if (arr[i]>=0)
        {
            if (i==0)
            {
                left[i]=1;
            }
            else
            {
                left[i]=left[i-1]+1;
            }
        }
        else
            left[i]=left[i-1];
    }
    for (int i = n-1; i>=0; --i)
    {
        if (arr[i]<=0)
        {
             if (i==n-1)
             {
               right[i]=1;
             }
             else
             {
                right[i]=right[i+1]+1;
             }
        }
        else
            right[i]=right[i+1];
      
    }
   int ans=INT_MAX;
   /* for (int i = 0; i < n; ++i)
    {
        cout<<left[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; ++i)
    {
        cout<<right[i]<<" ";
    }*/
    for (int i = 0; i < n-1; ++i)
    {
        ans=min(ans,left[i]+right[i+1]); //as we have to divide into two part that why right[i+1] :P
    }
    cout<<ans;


     
    return 0;
}
