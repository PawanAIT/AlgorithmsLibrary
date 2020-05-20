#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//selection sort
void select(int arr[],int n,int k)
{
	int i,j,temp,max=1000011;
	int	imax=i,count=0;
	for(i=0;i<n-1;i++)
    {
		imax=i;
		for(j=i+1;j<n;j++)
		{
		if(arr[imax]<arr[j])
			{
				imax=j;	
			}	
		}

		if(imax!=i)
		{
	       count++;
		swap(arr[i],arr[imax]);
		
		}
        if(count==k)break;
	}
	
}
int main() {
    int n,k,arr[1000000];
    cin>>n>>k;
   
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(k>n)
       { 
        for(int i=n;i>0;i--)
        cout<<i<<' ';
       }
    else
        {
        
    select(arr,n,k);
         for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
