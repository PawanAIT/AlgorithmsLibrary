#include <iostream>	
using namespace std;
int main(int argc, char const *argv[])
{
	int t,k,arr[2001],j=0;
	cin>>t>>k;
	for (int i = 0; i < t; ++i)
	{
		cin>>arr[i];
	}

	for (int i = 0; i < t-1; ++i)
	{
		while(arr[i]>=arr[i+1]) {
			if(arr[i]<=arr[i+1]+k)
				{
					arr[i+1]+=k;
					j++;
				}
				else
				{
		   			j+=(arr[i]-arr[i+1])/k;
		   			arr[i+1]+=((arr[i]-arr[i+1])/k)*k;
		  			
		  		}
		}
	}

	cout<<j;
	return 0;
}
