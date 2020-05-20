#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define LD long double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define bitcount _builtin_popcount
#define MOD 1000000007
#define MAXN 1<<10
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068

int T,N,i,j;
template<typename T>T absll(T X)
{
    if(X<0)
    {
        return -1*X;
    }
    else
        return X;
}
void mulAR(LL A[4][4],LL R[4])
{
    LL x=(A[0][0]*R[0])%MOD+(A[0][1]*R[1])%MOD+(A[0][2]*R[2])%MOD+(A[0][3]*R[3])%MOD;
    x%=MOD;
    LL y=(A[1][0]*R[0])%MOD+(A[1][1]*R[1])%MOD+(A[1][2]*R[2])%MOD+(A[1][3]*R[3])%MOD;
    y%=MOD;
    LL z=(A[2][0]*R[0])%MOD+(A[2][1]*R[1])%MOD+(A[2][2]*R[2])%MOD+(A[2][3]*R[3])%MOD;
    z%=MOD;
    LL w=(A[3][0]*R[0])%MOD+(A[3][1]*R[1])%MOD+(A[3][2]*R[2])%MOD+(A[3][3]*R[3])%MOD;
    w%=MOD;

    R[0]=x;
    R[1]=y;
    R[2]=z;
    R[3]=w;
}

void mulAA(LL A[4][4],LL R[4][4])
{
    LL L[4][4];
    memset(L,0,sizeof(L));
    L[0][0]=(A[0][0]*R[0][0])%MOD+(A[0][1]*R[1][0])%MOD+(A[0][2]*R[2][0])%MOD+(A[0][3]*R[3][0])%MOD;
    L[0][0]%=MOD;
    L[0][1]=(A[0][0]*R[0][1])%MOD+(A[0][1]*R[1][1])%MOD+(A[0][2]*R[2][1])%MOD+(A[0][3]*R[3][1])%MOD;
    L[0][1]%=MOD;
    L[0][2]=(A[0][0]*R[0][2])%MOD+(A[0][1]*R[1][2])%MOD+(A[0][2]*R[2][2])%MOD+(A[0][3]*R[3][2])%MOD;
    L[0][2]%=MOD;
    L[0][3]=(A[0][0]*R[0][3])%MOD+(A[0][1]*R[1][3])%MOD+(A[0][2]*R[2][3])%MOD+(A[0][3]*R[3][3])%MOD;
    L[0][3]%=MOD;

    L[1][0]=(A[1][0]*R[0][0])%MOD+(A[1][1]*R[1][0])%MOD+(A[1][2]*R[2][0])%MOD+(A[1][3]*R[3][0])%MOD;
    L[1][0]%=MOD;
    L[1][1]=(A[1][0]*R[0][1])%MOD+(A[1][1]*R[1][1])%MOD+(A[1][2]*R[2][1])%MOD+(A[1][3]*R[3][1])%MOD;
    L[1][1]%=MOD;
    L[1][2]=(A[1][0]*R[0][2])%MOD+(A[1][1]*R[1][2])%MOD+(A[1][2]*R[2][2])%MOD+(A[1][3]*R[3][2])%MOD;
    L[1][2]%=MOD;
    L[1][3]=(A[1][0]*R[0][3])%MOD+(A[1][1]*R[1][3])%MOD+(A[1][2]*R[2][3])%MOD+(A[1][3]*R[3][3])%MOD;
    L[1][3]%=MOD;

    L[2][0]=(A[2][0]*R[0][0])%MOD+(A[2][1]*R[1][0])%MOD+(A[2][2]*R[2][0])%MOD+(A[2][3]*R[3][0])%MOD;
    L[2][0]%=MOD;
    L[2][1]=(A[2][0]*R[0][1])%MOD+(A[2][1]*R[1][1])%MOD+(A[2][2]*R[2][1])%MOD+(A[2][3]*R[3][1])%MOD;
    L[2][1]%=MOD;
    L[2][2]=(A[2][0]*R[0][2])%MOD+(A[2][1]*R[1][2])%MOD+(A[2][2]*R[2][2])%MOD+(A[2][3]*R[3][2])%MOD;
    L[2][2]%=MOD;
    L[2][3]=(A[2][0]*R[0][3])%MOD+(A[2][1]*R[1][3])%MOD+(A[2][2]*R[2][3])%MOD+(A[2][3]*R[3][3])%MOD;
    L[2][3]%=MOD;

    L[3][0]=(A[3][0]*R[0][0])%MOD+(A[3][1]*R[1][0])%MOD+(A[3][2]*R[2][0])%MOD+(A[3][3]*R[3][0])%MOD;
    L[3][0]%=MOD;
    L[3][1]=(A[3][0]*R[0][1])%MOD+(A[3][1]*R[1][1])%MOD+(A[3][2]*R[2][1])%MOD+(A[3][3]*R[3][1])%MOD;
    L[3][1]%=MOD;
    L[3][2]=(A[3][0]*R[0][2])%MOD+(A[3][1]*R[1][2])%MOD+(A[3][2]*R[2][2])%MOD+(A[3][3]*R[3][2])%MOD;
    L[3][2]%=MOD;
    L[3][3]=(A[3][0]*R[0][3])%MOD+(A[3][1]*R[1][3])%MOD+(A[3][2]*R[2][3])%MOD+(A[3][3]*R[3][3])%MOD;
    L[3][3]%=MOD;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            A[i][j]=L[i][j];
        }
    }

}
void power(LL A[4][4],int N)
{
    if(N==0||N==1)
    {
        return;
    }
    LL B[4][4]={{5,-8,5,-1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
    power(A,N/2);
    mulAA(A,A);
    if(N%2)
    mulAA(A,B);
}

LL solve(int N)
{
    LL A[4][4]={{5,-8,5,-1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
    LL R[4]={17,5,1,0};
    power(A,N-1);
    mulAR(A,R);
    return (R[0]+MOD)%MOD;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;
		if(N==1)
        {
            cout<<"0"<<endl;
        }
        else if(N==2)
        {
            cout<<"1"<<endl;
        }
        else if(N==3)
        {
            cout<<"5"<<endl;
        }
        else if(N==4)
        {
            cout<<"17"<<endl;
        }
		else
        {
            cout<<solve(N-3)<<endl;
        }
	}
	return 0;
}

