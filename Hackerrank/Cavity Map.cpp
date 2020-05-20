#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,i,j;
    cin>>n;
    char arr[101][101];
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=1;i<n-1;i++)
        for(j=1;j<n-1;j++)
        {
        if(arr[i][j]>arr[i-1][j]&&arr[i][j]>arr[i+1][j]&&arr[i][j]>arr[i][j-1]&&arr[i][j]>arr[i][j+1])
            arr[i][j]='X';
        
    }
    for(i=0;i<n;i++)
       cout<<arr[i]<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
