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
#define MAXN 1000005
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

int T,N,M,P;
vector<int> ranks;
vector<int> parent;

void Make_Set(int &N)
{
	ranks.clear();
	parent.clear();
	ranks.resize(N,0);
	parent.resize(N,0);
	for(int i=0;i<N;i++)
	{
		parent[i]=i;
		ranks[i]=0;
	}
}

int Find_Set(int p)
{
	while(parent[p]!=p)
	{
		p=parent[p];
	}
	return p;
}

void Union_Set(int p,int q)
{
	int x=Find_Set(p);
	int y=Find_Set(q);
	
	if(ranks[x]<ranks[y])
	{
		parent[x]=y;
	}
	else if(ranks[x]>ranks[y])
	{
		parent[y]=x;
	}
	else
	{
		parent[y]=x;
		ranks[x]+=1;
	}
}

struct Edge
{
	int source;
	int destination;
	int weight;
};

vector<Edge> E;
bool comp(const Edge &A,const Edge &B)
{
	return A.weight<B.weight;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,M,P;
		scanf("%d",&P);
		scanf("%d",&N);
		scanf("%d",&M);
		E.clear();
		E.resize(M,{0,0,0});
		int A,B,C;
		Make_Set(N);
		/*for(int i=0;i<N;i++)
		{
			cout<<parent[i]<<" "<<ranks[i]<<endl;
		}*/
		
		for(int i=0;i<M;i++)
		{
			scanf("%d %d %d",&A,&B,&C);
			E[i].source=(--A);
			E[i].destination=(--B);
			E[i].weight=C*P;
		}
		
		sort(E.begin(),E.end(),comp);
		
		/*for(int i=0;i<E.size();i++)
		{
			cout<<E[i].source<<" "<<E[i].destination<<" "<<E[i].weight<<endl;
		}*/
		
		LL sol=0LL;
		for(int i=0;i<M;i++)
		{
			int X=Find_Set(E[i].source);
			int Y=Find_Set(E[i].destination);
			if(X!=Y)
			{
				//cout<<"wow"<<endl;
				Union_Set(E[i].source,E[i].destination);
				sol+=E[i].weight;
			}
		}
		printf("%lld\n",sol);
	}
	return 0;
}