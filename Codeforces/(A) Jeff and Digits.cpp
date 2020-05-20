#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t,w;
	cin>>t;
	int a[2]={0};

	while(t--) {
	   cin>>w;
	   if (w==5)
	   {
	   a[1]++;
	   }
	   else
	   	a[0]++;
	}

	
	if(a[0]==0)
		cout<<-1;
	else if (a[1]<3||( a[1]-a[1]%9)<=0)
	{
		cout<<0;
	}
		else
			{
				for (int i = 0; i < a[1]-a[1]%9; ++i)
				{
					cout<<5;
				}
				for (int i = 0; i < a[0]; ++i)
				{
					cout<<0;
				}
			}


}
