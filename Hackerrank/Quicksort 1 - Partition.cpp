#include<iostream>
using namespace std;
int main()
{
	
	int arr[100],arr1[1000],arr2[100],i,j,x,l=0,k=0,t;
	cin>>x;
	for(i=0;i<x;i++)
	{
		cin>>arr[i];
	}
	t=arr[0];
	for(i=0;i<x;i++)
	{
		if(arr[i]<t)
		{
			arr1[k++]=arr[i];
			
		}
		else
		{
		arr2[l++]=arr[i];
	
	}
}
	i=j=0;
	while(k--)
	{
		arr[i++]=arr1[j++];
	}
	j=0;
	while(l--)
	{
		arr[i++]=arr2[j++];
	}
	for(i=0;i<x;i++)
	{cout<<arr[i]<<" ";
	}
	return 0;
}
