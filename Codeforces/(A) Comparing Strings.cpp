#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int t=1;

    char arr[1000000],arr1[1000000];
    
    while(t--)
        {
        int a[26]={0},b[26]={0};
        int flag=0,count=0;
        cin>>arr>>arr1;
        for(int i=0;arr[i]!='\0';i++)
            a[arr[i]-'a']++;
        for(int i=0;arr1[i]!='\0';i++) 
           { 
            b[arr1[i]-'a']++;
            if(arr[i]!=arr1[i])
              count++;
        }
        
         for(int i=0;i<26;i++)
        
        {
        if(a[i]!=b[i])
            {
            //cout<<"NO"<<endl;
            flag=1;
            break;
            
        }
        
    }
    if(flag!=1&&count==2)
        cout<<"YES"<<endl;
      else
        cout<<"NO";
    }
   
    return 0;
}
