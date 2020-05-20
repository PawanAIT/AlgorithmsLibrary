#include <bits/stdc++.h>
using namespace std;
int x,y;
int arr[20][100];
int pow2[12]={0};
void solve(int level,int i,int j)
{
	if (level>x)
	{
		return ;
	}
	if (pow2[level]==arr[i][j])
	{
		
		solve(level+1,i+1,j);
		solve(level+1,i+1,j+1);
		//arr[i+1][j]++;
		//arr[i+1][j+1]++;
	}
	else
	{
		arr[i][j]++;
	}
}
int main()
{
	int count=0;
	for (int i = 0; i <=10; ++i)
	{
		pow2[i]=pow(2,i);
	}
	cin>>x>>y;
	for (int i = 0; i < y; ++i)
	{
		solve(0,0,0);
	}
	for (int i = 0; i < x; ++i)
	{
		for (int j=0; j <=i; ++j)
		{
			if (arr[i][j]==pow2[i])
			{
				count++;
			}
		}
	}
/*for (int i = 0; i < x; ++i)
	{
		for (int j=0; j <=i; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}*/
		cout<<count<<endl;
}
