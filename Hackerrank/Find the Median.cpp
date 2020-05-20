#include<iostream>
#include<math.h>
using namespace std;

int part(int *arr,int a,int b)
{
	int q=arr[b],j=a,i;
	
		for(i=a;i<b;i++)
	{
		if(arr[i]<=q)
		{
			swap(arr[i],arr[j]);
			j++;
	
		}
		
		
	}
	swap(arr[b],arr[j]);

	

	return j;
}
void quicksort(int *arr,int a,int b)
{
	
	
	if(a<b)
	{
		
		int p=part(arr,a,b);
	
		quicksort(arr,a,p-1);
		
		quicksort(arr,p+1,b);
	}
}

int main()
{
	int x,arr[100000],max=36232212;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		cin>>arr[i];
	}
	quicksort(arr,0,x-1);
	
if(x%2==0)
    {
    cout<<arr[x/2-1];
}
    else
        cout<<arr[x/2];
return 0;
}
