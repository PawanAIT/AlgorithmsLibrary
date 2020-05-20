#include<iostream>
using namespace std;
int q;
int part(int *arr,int a,int b)
{
	int i,j,k,m;
	 m=arr[b];
	 j=a;
	for(i=a;i<b;i++)
	 {
	  if(arr[i]<=m)
	 {
	 	swap(arr[i],arr[j]);
	 	j++;
	 }
}
	  	swap(arr[j],arr[b]);
	  	for(i=0;i<q;i++)
	  cout<<arr[i]<<" ";
	  cout<<endl;
	  return j;
}

void quicksort(int *arr,int a,int b)
{
	 int p;
	if(a<b)
	{
	p=part(arr,a,b);
	quicksort(arr,a,p-1);
	quicksort(arr,p+1,b);	
	}
	
}

int main()
{
 
int arr[100000],i;
    cin>>q;
    for(i=0;i<q;i++)
        {
        cin>>arr[i];
    }

quicksort(arr,0,q-1);

	return 0;	
	
}
