#include<iostream>
using namespace std;
int main()
{
	int arr[100],t,j,x,i,k;
	cin>>x;
	for(i=0;i<x;i++)
	{
		cin>>arr[i];
		
	}
	
	t=arr[x-1];
	j=x-2;
	for(i=x-1;i>0;--i)
	{
		if(t<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
			for(k=0;k<x;k++)
	{
		cout<<arr[k]<<" ";
		
	}
	cout<<endl;
	arr[j+1]=t;
		}
		else {
			break;
		}
	}

for(k=0;k<x;k++)
	{
		cout<<arr[k]<<" ";
		
	}
	}
		
	
	

	
	
