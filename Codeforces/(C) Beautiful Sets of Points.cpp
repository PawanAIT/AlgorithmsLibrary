#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	int m,n;
	cin>>m>>n;
	m=min(m,n)+1;
	cout<<m<<endl;
	for (int i = 0; i < m; ++i)
	{
		cout<<m-1-i<<" "<<i<<endl;
	}

     
	return 0;
}
