#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int r,c,m,n,i,j,arr[26][26],flag=0,q,t,flag1=0,max1=0;
    char str[26];
    cin>>r>>c;
    for(i=0;i<r;i++)
        {
        cin>>str;
        for(j=0;str[j]!='\0';j++)
        arr[i][j]=str[j]-'0';
    }
    
   
         for(m=1;m<=r;m++)
        for(n=1;n<=c;n++)
        
        {
             flag1=0;
            
               for(i=0;i<r-m+1;i++)
               {
                   for(j=0;j<c-n+1;j++)
                 {
                 flag=0;
                 for( q=0;q<m;q++)  
                 {
                     for( t=0;t<n;t++)
                    {
                         if(arr[i+q][j+t]!=0)
                         {  flag=1; 
                            break;
                         }
                   }
                 
                 if(flag==1){
                     break;
                     }
                 }
                 if(flag==0){
                    //cout<<m <<" "<<n<<endl;
                            max1=max(max1,2*((m)+n));
                         flag1=1;
                             break;
                 }
                 
             }
           if(flag1==1)break;
                   
               }
                
            
            }
        

cout<<max1;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
