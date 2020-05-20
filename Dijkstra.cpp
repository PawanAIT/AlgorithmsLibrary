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
#define MAXN 100005
#define bitcount _builtin_popcount
#define INF 2000000000
#define EPS 1e-9
#define PI 3.14159265359

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

int main()
{
	vector<LL> dist(N+2,INF);
	priority_queue<pair<LL,LL>,vector<pair<LL,LL> >,greater<pair<LL,LL> > > PQ;
	//Dijkstra Algorithm
	dist[M[sourcename]]=0LL;
	PQ.push(mp(0LL,M[sourcename]));
	while(!PQ.empty())
	{
		pair<LL,LL> top=PQ.top();
		PQ.pop();
		LL V=top.second;
		LL D=top.first;
		if(D<=dist[V])
		{
			vector<pair<LL,LL> >::iterator it;
			for(it=G[V].begin();it!=G[V].end();it++)
			{
				LL reachablevertex=it->first;
				LL cost=it->second;
				if(dist[reachablevertex]>dist[V]+cost)
				{
					dist[reachablevertex]=dist[V]+cost;
					PQ.push(mp(dist[reachablevertex],reachablevertex));
				}
			}
		}
	}

}
