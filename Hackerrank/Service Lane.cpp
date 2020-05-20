#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    	int arr[100000],n,a,b,i,j,z,t;
	
	scanf("%d",&n);
	
	scanf("%d",&t);
	for(i=0;i<n;i++)
	{
	  
	  scanf("%d",&arr[i]);
    }
     
     for(j=1;j<=t;j++)
     {z=5;
     
     	scanf("%d%d",&a,&b);
     	for(;a<=b;a++)
     	   
     	{  
		 if(z>arr[a])
     	   z=arr[a];
      
        }
          
        	printf("%d\n",z);
        
           
        
	}

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
