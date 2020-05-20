#include "bits/stdc++.h"
#define ll long long
using namespace std;

int m,n;
int dp[11][11];
int T[8][2]={{1,0},{0,1},{-1,1},{1,-1},{-1,0},{0,-1},{1,1},{-1,-1}};
int connected=0;
int arr[11][11];
int visited[11][11];
void dfs(int i,int j)
    {
    if(i<0||i>=m||j<0||j>=n||visited[i][j]||!arr[i][j])return;
    connected++;
    visited[i][j]=1;
    for(int k=0;k<8;k++)
        {
        dfs(i+T[k][0],j+T[k][1]);
    }
}
int main()
{	std::ios::sync_with_stdio(false);
	cin>>m>>n;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>arr[i][j];
		}
	}
	
	int ans=0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j <n; ++j)
		{
            if(arr[i][j])
            {
                dfs(i,j);
			     ans=max(ans,connected);
                connected=0;
            }
		}
	
	}
	cout<<ans;
    
	return 0;
}
