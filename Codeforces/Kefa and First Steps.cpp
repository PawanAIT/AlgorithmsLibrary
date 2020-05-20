#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int t,arr[100005],ans=0,count=0;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>arr[i];
	}
	
	for (int i = 0; i < t-1; ++i)
	{
		if(arr[i]<=arr[i+1])
		{
			count++;
		}
		else
			count=0;
		ans=max(count,ans);
	}
	cout<<ans+1;
	return 0;
}
