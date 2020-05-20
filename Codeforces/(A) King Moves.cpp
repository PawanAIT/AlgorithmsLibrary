#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	int arr[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
	char a,b;
	int  A,B;
	cin>>a>>b;
	A=a-'a';
	B=b-'0'-1;
	int count=0;
	for (int i = 0; i < 8; ++i)
	{
		if ((A+arr[i][0])>=0 && (B+arr[i][1])>=0 && (A+arr[i][0]<8 )&& B+arr[i][1]<8)
		{
			count++;
		}

	}
	cout<<count;


     
	return 0;
}
