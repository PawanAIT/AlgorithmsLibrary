#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int r,c,m,n,i,j,arr[1001][1001],A[1001][1001],flag=0,x,q,t,count=0,flag1=0;
    cin>>x;
    char str[10000];
    while(x--)
        {
        flag1=0;
        count=0;
    cin>>r>>c;
    for(i=0;i<r;i++)
        {
        cin>>str;
        for(j=0;str[j]!='\0';j++)
        arr[i][j]=str[j]-'0';
    }
        
        
        cin>>m>>n;
     for(i=0;i<m;i++)
         {
         cin>>str;
         for(j=0;str[j]!='\0';j++)
        A[i][j]=str[j]-'0';  
     }
     
       for(i=0;i<r-m+1;i++)
       {
           for(j=0;j<c-n+1;j++)
         {
         flag=0;
         for( q=0;q<m;q++)  
         {
             for( t=0;t<n;t++)
            {
                 if(arr[i+q][j+t]!=A[q][t])
                 {  flag=1; 
                    break;
                 }
           }
         
         if(flag==1){
             break;
             }
         }
         if(flag==0){
                 cout<<"YES\n";
                 flag1=1;
                     break;
         }
         
     }
   if(flag1==1)break;
           
       }
            
       if(i==r-m+1)cout<<"NO\n";
        
    
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
