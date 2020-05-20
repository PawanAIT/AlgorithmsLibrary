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
#define EPS 1e-6

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

void PP(int lc,int rc,string str)
{
    static int cnt=1;
	if(lc==0&&rc==0)
	{
		cout<<cnt<<" "<<str<<endl;
		++cnt;
	}

	if(lc>0)
	{
		PP(lc-1,rc,str+"(");
	}


	if(lc<rc)
	{
		PP(lc,rc-1,str+")");
	}
}
int main()
{
    string str="";
    int lc=6;
    int rc=6;
    PP(lc,rc,str);
	return 0;
}
