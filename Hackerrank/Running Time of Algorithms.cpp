#include<stdio.h>
main()
{
int temp,j,i,y=6,k,m=0;
    scanf("%d",&y);
    int arr[y];
    
  for(int i=0;i<y;i++)
scanf("%d",&arr[i]);


for( i=1;i<y;i++)
{
	temp=arr[i];
k=i;
while(k>0&&arr[k-1]>arr[k])
{
	arr[k]=arr[k-1];
	arr[k-1]=temp;
	k--;
    m++;
}


	}
	printf("%d ",m);
}




	
