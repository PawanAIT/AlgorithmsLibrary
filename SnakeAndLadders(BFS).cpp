#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define LD long double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 10000003
#define MAXN 5*1000001
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

map<int,int> ladder;
map<int,int> snake;

int BFS()
{
	queue<pair<int,int> > Q;
	vector<bool> visited(101,false);

    Q.push(mp(1,0));
    
	while(!Q.empty())
	{
		pair<int,int> H=Q.front();
		Q.pop();

		//cout<<H.first<<" "<<H.second<<endl;
		visited[H.first]=true;

		if(H.first==100)
		{
			return H.second;
		}

		for(int i=1;i<=6&&H.first+i<101;i++)
		{
			if(ladder[H.first+i]!=0&&!visited[H.first+i])
			{
				//cout<<"fss"<<endl;
				Q.push(mp(ladder[H.first+i],H.second+1));
			}
			else if(snake[H.first+i]!=0&&!visited[H.first+i])
			{
				//cout<<"hss"<<endl;
				Q.push(mp(snake[H.first+i],H.second+1));
			}
			else if(!visited[H.first+i])
			{
				//cout<<"yo"<<endl;
				Q.push(mp(H.first+i,H.second+1));
			}
		}
	}
    return -1;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ladder.clear();
		snake.clear();
		int N;
		scanf("%d",&N);
		int X,Y;
		for(int i=0;i<N;i++)
		{
			scanf("%d %d",&X,&Y);
			ladder[X]=Y;
		}

		int M;
		scanf("%d",&M);

		for(int i=0;i<M;i++)
		{
			scanf("%d %d",&X,&Y);
			snake[X]=Y;
		}
		printf("%d\n",BFS());
	}
	return 0;
}