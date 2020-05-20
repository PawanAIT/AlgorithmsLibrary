#include "iostream"
#include "math.h"
#include <stack>
#include <vector>
#include "process.h"
using namespace std;
int main()
{
	string s[8];
	int i,j;
	for (int i = 0; i < 8; ++i)
	{
		cin>>s[i];		
	}
	for ( i = 0; i < 8; ++i)
	{
		for ( j = 0; j < 7; ++j)
		{
			if(s[i][j]==s[i][j+1])
			{
				cout<<"NO";
				goto up;
			}
		}
	}
	up:
	if(i==8&&j==7)
		cout<<"YES";

}
