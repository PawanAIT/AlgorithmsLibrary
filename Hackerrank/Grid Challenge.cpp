#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    char arr[1001][1001];
    int i,j,k,t,n;
    cin>>t;
    while(t--)
        {
        cin>>n;
        for(i=0;i<n;i++)
        {cin>>arr[i];
         sort(arr[i],arr[i]+n);
    }
        for(i=0;i<n;i++)
           { for(j=0;j<n-1;j++)
           if(arr[j][i]>arr[j+1][i])
        {cout<<"NO"<<endl;break;}
        if(j<n-1)break;
           }
           
        if(i==n)
            cout<<"YES"<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
