#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    	int arr[11],y,i,a,m;
	
	scanf("%d",&y);
	
	
	for(i=0;i<y;i++)
	{ arr[i]=1;
	  
	   scanf("%d",&m);
	   
		for(a=0;a<m;a++)
	{
		if(a%2==0)
		{
			arr[i]=2*arr[i];
		}
		else
		arr[i]++;
	
    }
	}
	
	for(i=0;i<y;i++)
	printf("%d\n",arr[i]);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
