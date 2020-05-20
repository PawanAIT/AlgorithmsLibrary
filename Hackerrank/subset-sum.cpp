

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
int sum=9,arr[10000]={3, 34, 4, 12, 5, 2},i,j,n=6;
   // cin>>sum>>n;

 int **a=(int **)malloc((n+1)*sizeof(int*));
 for(i=0;i<=n;i++)
 a[i]=(int*)malloc((sum+1)*sizeof(int));
 
   // for(i=0;i<n;i++)
       // cin>>arr[i];
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
                a[i][j]=max(a[i-1][j-arr[i-1]],a[i-1][j]);
        }
    }
   for(i=0;i<=n;i++)
        {cout<<endl;
        for(j=0;j<=sum;j++)
            {
            cout<<a[i][j]<<" ";
        }
        }
   
    cout<<((a[i-1][j-1])?"yes":"no");
     
    return 0;
}
