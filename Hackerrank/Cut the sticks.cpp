#include<stdio.h>
//bubble sort
main()
{
	int i,j,k,x=6,z,count=0,c,v=100000;
	//printf("enter the no to be sorted");
   	scanf("%d",&x);
   	int arr[x];
   	for(i=0;i<x;i++)
   	{ //printf("enter the element %d : ",i+1);
   		scanf("%d",&arr[i]);
	}
   	
	   
	   for(i=0;i<(x-1);i++)	
   	for(j=0;j<(x-i-1);j++)
   	{
   		if(arr[j]<arr[j+1])
   		{
   			k=arr[j];
   			arr[j]=arr[j+1];
   			arr[j+1]=k;
   		}
   	}
   	
   	
   /*	printf("sorted array is ");
   	for(i=0;i<x;i++)
   		printf("%d  ",arr[i]);
   	
   	printf("\n");
	*/
	c=x;
	printf("%d\n",c);
	
	for(i=0;x!=0;i++)
	{  count=0;  
	z=arr[x-1];
		for(j=0;j<c;j++)
		{
			arr[j]=arr[j]-z;
		
		}
			x--;
			
		
		if(x!=0){	for(k=0;k<x;k++)
			if(arr[k]>0)
			count++;
			
			if(count<v&&count!=0)
			{
				printf("%d\n",count);
			}
			v=count;
	}		
		/*		for(k=0;k<c;k++)
		printf("%d  ",arr[k]);
		
		printf("\n");
	
		
		*/
	}
	
	
}
