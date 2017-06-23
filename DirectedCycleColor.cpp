#include<bits/stdc++.h>
using namespace std;
const int N = 1e4;
int color[N];
vector<int>v[N];
enum Color{WHITE,GREY,BLACK};
bool dfs(int node)
{
	if (color[node] == WHITE)
	{
		color[node] = GREY;
		for (auto i : v[node])
		{
			if (color[i] == WHITE)
			{
				if (dfs(i))return true;
			}
			if (color[i] == GREY)
				return true;
		}
	}
	color[node] = BLACK;
	return false;
}
int main()
{
	int n,L,R,e;
	bool flag = false;
	scanf("%d%d", &n,&e); //1 7 SB..#.T
	for (int i = 0; i < e; i++)
	{
		scanf("%d%d", &L, &R);
		v[L].push_back(R);
	}
	for (int i = 1; i <=n; i++)
	{
		if(color[i]==WHITE)
			if (dfs(i))
			{
				flag = true;
				break;
			}
	}
	if (flag)
		cout << "Cycle\n";
	else
		cout << "Not Cycle\n";

	return 0;
}

/*
6
7
1 2
2 3
1 3
4 1
4 5
5 6
6 4
*/