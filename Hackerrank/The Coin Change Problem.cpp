#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  long long  int sum,arr[10000],i,j,n;
    cin>>sum>>n;
 long long   int a[n+1][sum+1]={0};
    for(i=0;i<n;i++)
        cin>>arr[i];
     for(i=0;i<=n;i++)
        {
        for(j=0;j<=sum;j++)
            {
            if(j==0)
        a[i][j]=1;
            else
                a[i][j]=0;
        }
        }
    
  
    for(i=1;i<=n;i++)
        {
        for(j=1;j<=sum;j++)
            {
            if(arr[i-1]>j)
                a[i][j]=a[i-1][j];
            else
                a[i][j]=a[i-1][j]+a[i][j-arr[i-1]];
        }
    }
/*    for(i=0;i<=n;i++)
        {cout<<endl;
        for(j=0;j<=sum;j++)
            {
            cout<<a[i][j]<<" ";
        }
        }*/
   
    cout<<a[i-1][j-1];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
