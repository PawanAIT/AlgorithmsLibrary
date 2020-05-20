#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define LD long double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000000007
#define MAXN 1000003
#define bitcount __builtin_popcount
#define INF 2000000000
#define EPS 1e-9

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

map<string,map<string,int> >M;
map<string,bool> isPresent;
vector<string> names;

bool isBipartite(string src)
{
	map<string,int> color;
	for(vector<string>::iterator it=names.begin();it!=names.end();it++)
	{
		color[*it]=-1;
	}

	color[src]=1;

	queue<string> Q;
	Q.push(src);

	while(!Q.empty())
	{
		string str=Q.front();
		Q.pop();

		for(vector<string>::iterator it=names.begin();it!=names.end();it++)
		{
			if(M[str][*it]&&color[*it]==-1)
			{
				color[*it]=1-color[str];
				Q.push(*it);
			}
			else if(M[str][*it]&&color[*it]==color[str])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int T;
	freopen("input.txt","r",stdin);//redirects standard input
    freopen("output.txt","w",stdout);//redirects standard output
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		int N;
		scanf("%d",&N);

		names.clear();
		M.clear();
		isPresent.clear();

		for(int i=0;i<N;i++)
		{
			string A,B;
			cin>>A>>B;
			M[A][B]=1;
			M[B][A]=1;
			if(!isPresent[A])
			{
				names.pb(A);
				isPresent[A]=true;
			}

			if(!isPresent[B])
			{
				names.pb(B);
				isPresent[B]=true;
			}
		}
		string src=names[0];
		bool flag=isBipartite(src);
		if(flag)
		{
			printf("Case #%d: Yes\n",test);
		}
		else
		{
			printf("Case #%d: No\n",test);
		}
	}
	return 0;
}
