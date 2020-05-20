#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int i,j=0,k,l,m,n,t,arr[100000],b[100000]={0};
    cin>>t;
    while(t--)
        {
        cin>>m>>n;
        for(i=0;i<n;i++)
           { cin>>arr[i];
            b[arr[i]]++;
           }
         for(i=0;i<n;i++)
            for(j=0;j<n;j++)
             {
             if(i!=j&&i>j)
             if(arr[i]+arr[j]==m)
                 cout<<j+1<<" "<<i+1<<endl;
         }
        
        
    }
    
    return 0;
}
