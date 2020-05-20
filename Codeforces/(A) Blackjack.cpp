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
{	std::ios::sync_with_stdio(false);
    clock_t start = clock();
	int n;
    cin>>n;
	if (n<=10||n>21)
	{
		cout<<0;
	}
	else
	{
		if (n==20)
		{
			cout<<15;
		}
		
		else
			cout<<4;
	}
    clock_t end = clock();
   // cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	return 0;
}
