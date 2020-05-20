#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	int row[100005]={0},col[100005]={0};
	ll n,m,p,q;
	int k=0,r=0,c=0;
	cin>>n>>m;
	ll ans=n*n;
	for (int i = 0; i < m; ++i)
	{
		cin>>p>>q;
		if (row[p]==0&&col[q]==0)
		{
			row[p]=1,col[q]=1;
			ans=ans-(2*n-1)+r+c;
			r++,c++;
			//k=k+2;
			//r++,c++;
		}
		else if (row[p]==0&&col[q]==1)
		{
			row[p]=1;
			ans=ans-(n)+c;
			r++;
		}
		else if(col[q]==0&&row[p]==1)
		{
			col[q]=1;
			ans=ans-(n)+r;
			c++;
		}

		cout<<ans<<" ";
	}

     
	return 0;
}
