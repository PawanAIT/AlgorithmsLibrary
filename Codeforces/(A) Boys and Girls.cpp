#include "bits/stdc++.h"
#define ll __int64
using namespace std;
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}
int main()
{	

	std::ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    clock_t start = clock();
	int m,n;
	cin>>n>>m;
	if(n>m)
	for (int i = 0; i < n; ++i)
	{
		cout<<'B';
		if(m){
			cout<<'G';
			m--;
		}
	}
	else
	{
		for (int i = 0; i < m; ++i)
		{
			cout<<'G';
			if (n)
			{
				cout<<'B';
				n--;
			}
		}
	}
    clock_t end = clock();
   // cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	return 0;
}
