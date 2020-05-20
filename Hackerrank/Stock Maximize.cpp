#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long int i,j,k,n,t,arr[100000],max1=-1,b,m;
    cin>>t;
    while(t--)
        {
        long long sum=0;
       
         cin>>n;
        for(i=0;i<n;i++)
            cin>>arr[i];
        max1=0;
        for(i=n-1;i>=0;i--)
            {
           if(max1<arr[i])
               max1=arr[i];
            sum=sum+(max1-(arr[i]));
        }
           
  cout<<sum<<endl;
}
    return 0;
}

