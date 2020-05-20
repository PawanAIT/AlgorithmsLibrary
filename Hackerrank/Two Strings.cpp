#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int t;
    cin>>t;
    char arr[1000000],arr1[1000000];
    
    while(t--)
        {
        int a[26]={0},b[26]={0};
        int flag=0;
        cin>>arr>>arr1;
        for(int i=0;arr[i]!='\0';i++)
            a[arr[i]-'a']++;
        for(int i=0;arr1[i]!='\0';i++)
            b[arr1[i]-'a']++;
        
        
         for(int i=0;i<26;i++)
        
        {
        if(a[i]>0&&b[i]>0)
            {
            cout<<"YES"<<endl;
            flag=1;
            break;
            
        }
        
    }
    if(flag!=1)
        cout<<"NO"<<endl;
    }
   
    return 0;
}
