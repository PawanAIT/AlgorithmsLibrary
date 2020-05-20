#include<stdio.h>
void func(int *arr, int n, int m)
{
	int i,j=0,flag = 0,max;
	max = arr[0];
	for(i = 1 ; i<n ; i++ )
	{
		if(arr[i] > max)
		{
			max = arr[i];
			j = i;
		}
	}
	if(max == arr[0])
	{
		for(i = 1; i<n ; i++)
		{
			if(arr[i] == max)
				flag = 1;
		}
		if(flag == 0)
		{
			printf("%d",max - m);return;
		}
		else
		{
			printf("%d",(max+1) - m);return;
		}
	}
	if(j>0)
	--arr[j];
	++arr[0];
	func(arr, n, m);
}
int main()
{
	int n, i;
	scanf("%d",&n);
	int arr[n], max;
	for(i=0 ; i<n ; i++)
		scanf("%d",&arr[i]);
		
	func(arr, n, arr[0]);
	
}
