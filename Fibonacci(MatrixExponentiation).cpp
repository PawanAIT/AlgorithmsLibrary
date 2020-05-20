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
#define MAXN 1000000
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

void MatrixMultiplication(LL F[2][2],LL M[2][2])
{
    LL x=((F[0][0]*M[0][0])%MOD+(F[0][1]*M[1][0])%MOD)%MOD;
    LL y=((F[0][0]*M[0][1])%MOD+(F[0][1]*M[1][1])%MOD)%MOD;
    LL z=((F[1][0]*M[0][0])%MOD+(F[1][1]*M[1][0])%MOD)%MOD;
    LL w=((F[1][0]*M[0][1])%MOD+(F[1][1]*M[1][1])%MOD)%MOD;
 
    F[0][0]=x%MOD;
    F[0][1]=y%MOD;
    F[1][0]=z%MOD;
    F[1][1]=w%MOD;
}

void MatrixExponentiation(LL F[2][2],LL N)
{
    if(N==0||N==1)
    {
        return;
    }
    LL M[2][2]={{1,1},{1,0}};
 
    MatrixExponentiation(F,N/2);
    MatrixMultiplication(F,F);
 
    if(N%2!=0)
    {
        MatrixMultiplication(F,M);
    }
}

LL Fibonacci(LL N)
{
    LL F[2][2]={{1,1},{1,0}};
    if(N==0)
    {
        return 0;
    }
    MatrixExponentiation(F,N-1);
    return F[0][0]%MOD;
}

int main()
{
	//std::clock_t start;
    //double duration;
    //start = std::clock();
    //freopen("input.in","r",stdin);//redirects standard input
    //freopen("output.out","w",stdout);//redirects standard output

    //duration=(clock()-start)/(double)CLOCKS_PER_SEC;
    //printf("\n\nDuration :- %0.9lf s",duration);
	return 0;
}