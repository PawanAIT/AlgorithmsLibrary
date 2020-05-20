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

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

int T,N; 
double A[5][5],B[4],coeff[4];
double ct,cv;

void gauss_eliminate(double A[5][5],double *x,int n)
{
	for(int e=0;e<4;e++)
	{
		for(int i=e;i<4;i++)
		{
			if(absll(A[i][e])>EPS)
			{
				if(i!=e)
				{
					for(int j=0;j<=4;j++)
					{
						swap(A[i][j],A[e][j]);
					}
				}
				break;
			}
		}
		for(int i=0;i<4;i++)
		{
			if(i==e)
			{
				continue;
			}
			double co=-A[i][e]/A[e][e];
			for(int j=0;j<=4;j++)
			{
				A[i][j]+=A[e][j]*co;
			}
		}
	}
	
	for(int i=0;i<4;i++)
	{
		coeff[i]=A[i][4]/A[i][i];
	}
}
