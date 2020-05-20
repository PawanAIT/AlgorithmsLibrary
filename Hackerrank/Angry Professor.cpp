#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

int n,t,k,sum=0,p=0,a[10000],i=0,j;
 
   scanf("%d",&t);    
 
  
     for(j=0;j<t;j++)
{      
       sum=0;
         
         scanf("%d",&n);
 
    scanf("%d",&k);
  
         for(i=0;i<n;i++)
        { 
		
		 scanf("%d",&a[i]);
         
        }
    
    
         for(i=0;i<n;i++)
    {  
             if(a[i]<=0)
      sum++;
   
   }
   
    
   
    
  if(sum>=k)
      
        printf("NO\n");
   
    
    else if(sum<k)
        printf("YES\n");

        
}

}
