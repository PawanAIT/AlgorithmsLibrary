#include"stdio.h"
#include"math.h"
void call(int a,int arr[10])
{ 
  int i=0;
	while(a)
	{
		arr[i]=a%2;
		a=a/2;
		i++;
	
	}

}

int xor1(int a,int b)
{
	int arr[20], arr1[20],arr2[20],i,sum=0;
	for(i=0;i<20;i++)
	arr[i]=arr1[i]=0;
	call(a,arr);
	call(b,arr1);
 i=0;	 
while(i<19)
{	 
	 if(arr[i]==arr1[i])
	 arr2[i]=0;
	 else
	 arr2[i]=1;
	 i++;
}
	
for(i=0;arr2[i]==1||arr2[i]==0;i++)
	sum+=(arr2[i]*pow(2,i));
	return sum;
}



main()
{
	 int a,b,i,j,sum,max=0;
	 scanf("%d %d",&a,&b);
	


for(i=a;i<=b;i++)
{
	
	for(j=i;j<=b;j++)
	{
		
	
	sum=0;
   sum=xor1(i,j);
   
   if(sum>max)
   max=sum;

}
}

printf("%d",max);

}
