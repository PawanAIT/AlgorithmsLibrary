#include "bits/stdc++.h"
#define ll __int64
using namespace std;
int arr[100005]={0};
int  seg[100000]={0};
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}
void build(int low ,int high,int pos)
{
	if (high==low)
	{
		seg[pos]=arr[low]%2;
		return ;
	}
	build(low,(low+high)/2,2*pos+1);
	build((low+high)/2+1,high,2*pos+2);
	seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
void update(int low ,int high,int ql,int qh,int pos)
{
	if (ql>high||qh<low)
	{
		return ;
	}
	if (ql<=low&&qh>=high)
	{
		seg[pos]=1-seg[pos];
		return;
	}
	update(low,(low+high)/2,ql,qh,2*pos+1);
	update((low+high)/2+1,high,ql,qh,2*pos+2);
	seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
int query(int low,int high,int ql ,int qh,int pos)
{
	if (ql>high||qh<low)
	{
		return 0;
	}
	if (ql<=low&&qh>=high)
	{
		return seg[pos];
	}
	int x=query(low,(low+high)/2,ql,qh,2*pos+1);
	int y=query((low+high)/2+1,high,ql,qh,2*pos+2);
	return x+y;
}
int main()
{	std::ios::sync_with_stdio(false);
    clock_t start = clock();
	int n,m;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	build(0,n-1,0);
	for (int i = 0; i < 20; ++i)
	{
		cout<<seg[i]<<" "; 
	}
	cout<<endl;
	cin>>m;
	int q,low,high;
	for (int i = 0; i < m; ++i)
	{
		cin>>q>>low>>high;
		if (q==0)
		{
			if (high%2==0 && arr[low-1]%2==1)
			{
				update(0,n-1,low-1,low-1,0);
			}
			if (high%2==1 && arr[low-1]%2==0)
			{
				update(0,n-1,low-1,low-1,0);
			}
			
		}else if(q==2)
		{
			cout<<query(0,n-1,low-1,high-1,0);
		}
		else
		{
			cout<<(high-low+low!=high)-query(0,n-1,low-1,high-1,0);
		}cout<<endl;
		for (int i = 0; i < 20; ++i)
		{
			cout<<seg[i]<<" ";
		}
		
	}


    clock_t end = clock();
   // cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	return 0;
}