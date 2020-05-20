
 #include <cstdio>
#include "bits/stdc++.h"
#include <algorithm>

using namespace std;

int main()
{
		int t;
		cin>>t;
		int m,n,sum=0;
		int m1[101]={0},n1[101]={0};
		while(t--) {
		    cin>>m>>n;
		    m1[m]++;
		    n1[n]++;
		}
		for (int i = 0; i <=100; ++i)
		{
			sum+=m1[i]*n1[i];
					}
					cout<<sum;
}
