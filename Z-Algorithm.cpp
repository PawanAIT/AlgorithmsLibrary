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

void swap_row(vector<vector<int> > &V,int row1,int row2,int N,int M)
{
	for(int i=0;i<M;i++)
	{
		int temp=V[row1][i];
		V[row1][i]=V[row2][i];
		V[row2][i]=temp;
	}
}

int MatrixRank(vector<vector<int> > &V,int N,int M)
{
	int r,c;
	
	for(r=0;r<M;r++)
	{
		if(V[r][r])
		{
			for(c=0;c<N;c++)
			{
				if(c!=r)
				{
					float ratio=(float)V[c][r]/(float)V[r][r];
					for(int i=0;i<M;i++)
					{
						V[c][i]-=ratio*V[r][i];
					}
				}
			}
		}
		else
		{
			for(c=r+1;c<N;c++)
			{
				if(V[c][r])
				{
					swap_row(V,r,c,N,M);
					break;
				}
			}
			
			if(c==N)
			{
				--M;
				for(c=0;c<N;c++)
				{
					V[c][r]=V[c][M];
				}
			}
			--r;
		}
	}
	return M;
}
vector<int> ZAlgorithm(string str,int N)
{
	int L=0,R=0;
	vector<int> Z(N,0);
	for(int i=1;i<N;i++)
	{
		if(i>R)
		{
			L=R=i;
			while(R<N&&str[R-L]==str[R])
			{
				++R;
			}
			Z[i]=R-L;
			--R;
		}
		else
		{
			int K=i-L;
			if(Z[K]<R-i+1)
			{
				Z[i]=Z[K];
			}
			else
			{
				L=i;
				while(R<N&&str[R-L]==str[R])
				{
					++R;
				}
				Z[i]=R-L;
				--R;
			}
		}
	}
	return Z;
}

int main()
{
	int T;
	cin>>T;
	for(int test=1;test<=T;test++)
	{
		string str;
		cin>>str;
		LL sol;
		int N=str.length();
		vector<int> Z=ZAlgorithm(str,N);
		for(int i=0;i<N;i++)
		{
			if(Z1[i]==N-i)
			{
				sol=max(sol,(LL)Z1[i]);
			}
		}
		if(sol==0)
		{
			sol=-1;
		}
		cout<<"Case "<<test<<":"<<sol<<endl;
	}
	return 0;
}