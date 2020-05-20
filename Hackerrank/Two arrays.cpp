#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int A[10000],B[10000],i,j;
    int t,n,k;
    cin>>t;
    while(t--)
        {
        int count=0;
        cin>>n>>k;
        for(i=0;i<n;i++)cin>>A[i];
          for(i=0;i<n;i++)cin>>B[i];
        sort(A,A+n);
        sort(B,B+n);
        for(i=0;i<n;i++)
            if(A[i]+B[n-i-1]<k)
        { cout<<"NO"<<endl;break;}
        if(i==n)
            cout<<"YES"<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
