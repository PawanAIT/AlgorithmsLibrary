#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n,arr[1000000],result=0,count=0,i;
    cin>>n;
    for( i=0;i<n;i++)
        {
        cin>>arr[i];
        result=result^arr[i];
    }
  
    for(i=0;i<n;i++)
        {
        if((result^arr[i])<arr[i])
            count++;
       
    }
    cout<<count;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
