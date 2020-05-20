#include<stdio.h>
//bubble sort
int main()
{
	int i,j,k,x;

   	scanf("%d",&x);
   	int arr[x];
   	for(i=0;i<x;i++)
   	{
   		scanf("%d",&arr[i]);
	}
   	
	   
	   for(i=0;i<(x-1);i++)	
   	for(j=0;j<(x-i-1);j++)
   	{
   		if(arr[j]>arr[j+1])
   		{
   			k=arr[j];
   			arr[j]=arr[j+1];
   			arr[j+1]=k;
   		}
   	}
   	
   	
   	
   	for(i=0;i<x;i++)
   		printf("%d ",arr[i]);
   	
   	return 0;
	
	
}
