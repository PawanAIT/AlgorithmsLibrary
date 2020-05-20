#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	float m,n,q;
	cin>>m>>n>>q;
	float temp=m/n*q;
	temp=sqrt(temp);
	float a,b,c;
	a=temp;
	b=m/temp;
	c=n/b;

	cout<<4*(a+b+c);



	
	return 0;
}
