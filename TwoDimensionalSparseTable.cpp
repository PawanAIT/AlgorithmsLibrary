#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define LD double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000000007LL
#define MAXN 123456
#define bitcount __builtin_popcount
#define INF 2000000000
#define EPS 1e-9
#define PI 3.14159265359
#define DEBUG 1
#define read(X) scanf("%lld",&X)
#define write(X) printf("%lld\n",&X)
 
template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

struct P
{
    int first;
    int second;
    
    P()
    {
        first=0;
        second=0;
    }
    
}pre[11][11][1004][1004];

int dp[1001][1001];
int A[1000][1000];

P get_max(P C,P D)
{
    int el1=A[C.first][C.second];
    int el2=A[D.first][D.second];

    if(el1>=el2)
    {
        return C;
    }
    else
    {
        return D;
    }
}

void TwoDimensionSparseTable(int N,int M)
{
    for(int i=0;(1<<i)<=N;i++)
    {
        for(int j=0;(1<<j)<=M;j++)
        {
            for(int x=0;x+(1<<i)-1<N;x++)
            {
                for(int y=0;y+(1<<j)-1<M;y++)
                {
                    if(i==0&&j==0)
                    {
                        pre[i][j][x][y].first=x;
                        pre[i][j][x][y].second=y;
                    }
                    else if(i==0)
                    {
                        pre[i][j][x][y]=get_max(pre[i][j-1][x][y],pre[i][j-1][x][y+(1<<(j-1))]);
                    }
                    else if(j==0)
                    {
                        pre[i][j][x][y]=get_max(pre[i-1][j][x][y],pre[i-1][j][x+(1<<(i-1))][y]);
                    }
                    else
                    {
                        pre[i][j][x][y]=get_max(get_max(pre[i-1][j-1][x][y],pre[i-1][j-1][x+(1<<(i-1))][y]),get_max(pre[i-1][j-1][x][y+(1<<(j-1))],pre[i-1][j-1][x+(1<<(i-1))][y+(1<<(j-1))]));
                    }
                }
            }
        }
    }
}

P get_range_max_query(int X,int Y,int X1,int Y1)
{
    int K=31- __builtin_clz(X1-X+1);
    int L=31- __builtin_clz(Y1-Y+1);
    P sol=get_max(get_max(pre[K][L][X][Y],pre[K][L][X1-(1<<K)+1][Y]),get_max(pre[K][L][X][Y1-(1<<L)+1],pre[K][L][X1-(1<<K)+1][Y1-(1<<L)+1]));
    return sol;
}