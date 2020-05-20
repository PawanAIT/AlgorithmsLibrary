#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,arr[100][100],sum=0,sum1=0;
    cin>>t;
    for(int i=0;i<t;i++)
        {
        for(int j=0;j<t;j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<t;i++)
       { sum+=arr[i][i] -arr[i][t-i-1];
    
       }
    
    cout<<fabs(sum);
    return 0;
}
