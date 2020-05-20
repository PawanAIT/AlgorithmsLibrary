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
#define MAXN 2*100005
#define bitcount _builtin_popcount
#define INF 2000000000
#define EPS 1e-9

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

bool comp(const pair<int,int> &A,const pair<int,int> &B)
{
	if(A.second==B.second)
	{
		return A.first<B.first;
	}
	return A.second<B.second;
}

int cx,cy;

bool comp2(const pair<int,int> &A,const pair<int,int> &B)
{
	double ang1=atan(((A.second-cy)*1.00000)/(A.first-cx)*1.000000);
	double ang2=atan(((B.second-cy)*1.00000)/(B.first-cx)*1.000000);
	if(ang1==ang2)
	{
		return ((A.first-cx)*(A.first-cx)+(A.second-cy)*(A.second-cy))<((B.first-cx)*(B.first-cx)+(B.second-cy)*(B.second-cy));
	}
	return ang1<ang2;
}

int orientation(const pair<int,int> &A,const pair<int,int> &B,const pair<int,int> &C)
{
	int val=(B.second-A.second)*(C.first-B.first)-(C.second-B.second)*(B.first-A.first);
	if(val==0)
	{
		return 0;//for collinear
	}
	return val>0?1:2;//clock or anticlock
}

pair<int,int> secondEle(stack<pair<int,int> > &S)
{
	pair<int,int> P=S.top();
	S.pop();
	pair<int,int>  Q=S.top();
	S.push(P);
	return Q;
}

int main()
{
	int N;
	cin>>N;
	vector<pair<int,int> > V(N,mp(0,0));
	
	for(int i=0;i<N;i++)
	{
		cin>>V[i].first>>V[i].second;	
	}
	sort(V.begin(),V.end(),comp);

	cx=V[0].first;
	cy=V[0].second;
		
	sort(V.begin(),V.end(),comp2);

	stack<pair<int,int> > S;
	S.push(V[0]);
	S.push(V[1]);
	S.push(V[2]);
	
	for(int i=3;i<N;i++)
	{
		while(orientation(secondEle(S),S.top(),V[i])!=2)
		{
			S.pop();
		}
		S.push(V[i]);
	}
	
	while(!S.empty())
	{
		pair<int,int> P=S.top();
		cout<<P.first<<" "<<P.second<<endl;
		S.pop();
	}
	return 0;
}
