#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;


int main() {
   
     int x,t,len,i;
    char arr[10001],m[10000],n[10000];
    cin>>t;
    while(t--)
        {
        int a[26]={0},b[26]={0};
        int count=0;
        cin>>arr;
       len= strlen(arr);
        if(len%2==0)
            {
            for(i=0;i<len/2;i++)
             {
              m[i]=arr[i];
                a[arr[i]-'a']++;
            }
               
            for(i=len/2;i<len;i++)
               { n[i]=arr[i];
                 b[arr[i]-'a']++;
               }
         
            for(i=0;i<26;i++)
                {
                if(a[i]!=b[i])
                   {
                    count+=fabs(a[i]-b[i]);
                }
             
            }
          
      cout<<count/2<<endl;
        
        }
                     else
            cout<<-1<<endl;
          
    }
    
     return 0;
}


