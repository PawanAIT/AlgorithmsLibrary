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
#define PI 3.14159265359
#define DEBUG 1
#define read(X) scanf("%lld",&X)
#define write(X) printf("%lld\n",&X)
#define ROOT_FIVE_MOD  474848249

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}
 
LL modPow(LL A,LL B,LL C)
{
    LL X=1LL;
    while(B)
    {
        if(B%2==1)
        {
            X=(X*A)%C;
        }
        A=(A*A)%C;
        B=B/2;
    }
    return X%C;
}

LL TonelliShanks(LL N,LL P)
{
    LL S=0;
    LL Q=P-1;

    while((Q&1)==0)
    {
        Q/=2LL;
        ++S;
    }

    if(S==1)
    {
        LL R=modPow(N,(P+1)/4,P);
        if((R*R)%P==N)
        {
            return R;
        }
        return 0LL;
    }

    LL Z=1LL;

    while(modPow(++Z,(P-1)/2LL,P)!=P-1);    

    LL C=modPow(Z,Q,P);
    LL R=modPow(N,(Q+1)/2,P);
    LL T=modPow(N,Q,P);
    LL M=S;

    while(T!=1)
    {
        LL TT=T;
        LL i=0;

        while(TT!=1)
        {
            TT=(TT*TT)%P;
            ++i;
            if(i==M)
            {
                return 0LL;
            }
        }

        LL B=modPow(C,modPow(2LL,M-i-1,P-1),P);
        LL B2=(B*B)%P;
        R=(R*B)%P;
        T=(T*B2)%P;
        C=B2;
        M=i;
    }
    if((R*R)%P==N)
    {
        return R;
    }
    return 0;    
}

LL getRoot(LL N,LL P)
{
    if(P%4==3)
    {
        return modPow(N,(P+1)/4,P);
    }
    else if(P%8==5)
    {
        if(modPow(N,(P-1)/4,P)==1)
        {
            return modPow(N,(P+3)/8,P);
        }
        else
        {
            LL ret=modPow(N,(P+3)/8,P);
            ret=(ret*modPow(2,(P-1)/4,P))%P;
            return ret;
        } 
    }
    else 
    {
        return TonelliShanks(N,P);
    }
}

int main()
{
    //std::clock_t start;
    //double duration;
    //start = std::clock();
    //freopen("input.in","r",stdin);//redirects standard input
    //freopen("output.out","w",stdout);//redirects standard output
    
    LL root5=getRoot(5LL,MOD*1LL);    
    //duration=(clock()-start)/(double)CLOCKS_PER_SEC;
    //printf("\n\nDuration :- %0.9lf s",duration);
    return 0;
} 
