#include "iostream"
#include "algorithm"
#include <string.h>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{

	int m,n;
	cin>>m>>n;
	int arr[10000];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	sort(arr,arr+n);
	
		int ans=10000;
	for (int i = 0; i+m-1 < n; ++i)
	{
		ans=min(ans,arr[i+m-1]-arr[i]);
	}


	cout<<ans;
	return 0;
}
