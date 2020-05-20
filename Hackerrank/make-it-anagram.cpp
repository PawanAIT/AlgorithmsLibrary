#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;


int main() {
   
     int x,t,len,i;
    char arr[10001],m[10000];
   
        int a[26]={0},b[26]={0};
        int count=0;
        cin>>arr;
        cin>>m;
      

            for(i=0;arr[i]!='\0';i++)
                a[arr[i]-'a']++;
        
               
            for(i=0;m[i]!='\0';i++)
               {
                 b[m[i]-'a']++;
               }
         
              
            for(i=0;i<26;i++)
                {
                if(a[i]!=b[i])
                   {
                    count+=fabs(a[i]-b[i]);
                }
             
            }
          
      cout<<count<<endl;
          return 0;
        }
    
   



