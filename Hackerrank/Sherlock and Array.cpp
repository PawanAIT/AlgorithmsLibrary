#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int arr[1000000];
    int i,j,k;long long int sum=0,sum2=0,m;
    cin>>k;
    while(k--)
        {
        int flag=-1;sum=0;sum2=0;
        cin>>j;
        if(j==1)
            {
            cin>>m;cout<<"YES"<<endl;
            }
        else{
        for(i=0;i<j;i++)
            {
            cin>>arr[i];
            sum+=arr[i];
        }
        for(i=0;i<j-1;i++)
            {
            sum2+=arr[i];
            sum-=arr[i];
            if(sum2==sum-arr[i+1])
                {
                cout<<"YES"<<endl;
                 flag=1;
                break;
               
            }
           
        }
        if(flag!=1)
            {
            cout<<"NO"<<endl;
        }
        }
    }
    return 0;
}
