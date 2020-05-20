#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
     int t;
    cin>>t;
    while(t--)
        {
        int arr[1000000];
        int ans=0,ans1=0,sum=0,n,count=0,min1=-3200000;
        cin>>n;
         for(int i=0;i<n;i++)
             cin>>arr[i];
       for(int i=0;i<n;i++)
           {
           if(arr[i]>0)
               ans1+=arr[i];
           else count++;
           if(sum+arr[i]>0)
               sum+=arr[i];
           else
               sum=0;
           ans=max(ans,sum);
           if(min1<arr[i])
               min1=arr[i];
       }
        if(count==n)
            {
            ans1=ans=min1;
              cout<<ans<<" "<<ans1<<endl;
        }
        else
        cout<<ans<<" "<<ans1<<endl;
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
