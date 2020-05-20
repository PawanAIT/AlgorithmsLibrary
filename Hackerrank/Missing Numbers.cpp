#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int a[1000010]={0},b[1000010]={0},i,j,k;
    cin>>j;
    for(i=0;i<j;i++)
        {
        cin>>k;
        a[k]++;
        
    }
     cin>>j;
    for(i=0;i<j;i++)
        {
        cin>>k;
        b[k]++;
        
    }
     for(i=0;i<=1000010;i++)
         {
         if(a[i]<b[i])
             {
             cout<<i<<" ";
         }
     }
    
    return 0;
}
