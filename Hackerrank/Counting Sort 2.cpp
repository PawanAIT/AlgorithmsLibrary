#include<iostream>

int z=0;
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
		z++;
		}
		
		
	}
	swap(arr[b],arr[j]);
	z++;
	

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
    int arr[1000000],a;
    cin>>a;
 for(int i=0;i<a;i++)
     {
     cin>>arr[i];
 }
    quicksort(arr,0,a-1);
    for(int i=0;i<a;i++)
     {
     cout<<arr[i]<<" ";
 }
    
}
