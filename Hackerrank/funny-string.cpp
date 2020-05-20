#include <cmath>
#include <cstdio>
#include <vector>
#include<string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
   
while(t--)
    
    {
     char arr[1000000];
cin>>arr;
    int i;
int n=strlen(arr);
for(i=1;i<n;i++)
    
    if(abs(int(arr[i])-int(arr[i-1]))==abs(int(arr[n-i])-int(arr[n-1-i])))
        continue;
    else 
        {
        cout<<"Not Funny"<<endl;
        break;
        exit(0);
    }
        if(i==strlen(arr))
        cout<<"Funny"<<endl;
}
    return 0;
}


