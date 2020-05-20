#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[2010][2010];
int main() {
  long long  int sum,arr[10000],i,j,n;
    int t;
    cin>>t;
    while(t--)
        {
    cin>>n>>sum;

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
/*   for(i=0;i<=n;i++)
        {cout<<endl;
        for(j=0;j<=sum;j++)
            {
            cout<<a[i][j]<<" ";
        }
        }
   printf("\n\n");*/
        i=n;
for(j=sum+1;j>0;j--)
    {
        {if(a[i][j-1])
        {cout<<j-1<<endl;break;}
    }
}
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
