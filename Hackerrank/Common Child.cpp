#include <cmath>
#include <cstdio>
#include<string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 int arr[5001][5001];

int main() {
 
    char a[5001],b[5001];
    cin>>a;
    cin>>b;
    
    int t=strlen(a),i,j;
   
    
    for(i=0;i<t+1;i++)
    {
       arr[0][i]=0;
        arr[i][0]=0;
    }
    for(i=1;i<t+1;i++)
    {
        for(j=1;j<t+1;j++)
        {
           if(a[i-1]==b[j-1])
               {
               arr[i][j]=arr[i-1][j-1]+1;
           }
            else
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    }
  
    
 cout<<arr[t][t];
    
    return 0;
}
