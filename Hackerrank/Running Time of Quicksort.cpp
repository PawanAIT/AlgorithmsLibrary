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



#include<stdio.h>
int main(){

  int i,j,s,temp,a[100000]={1,3,9,8,2,7,5},b[100000],k=0;


cin>>s;

 
  for(i=0;i<s;i++)
      {
	  cin>>a[i];
      b[i]=a[i];
      }

quicksort(b,0,s-1);

   for(i=1;i<s;i++){
      temp=a[i];
      j=i-1;
      while((temp<a[j])&&(j>=0))
	  {
      a[j+1]=a[j];
          j=j-1;
          k++;
      }
      a[j+1]=temp;
  }

  

 cout<<k-z;

  return 0;
}




