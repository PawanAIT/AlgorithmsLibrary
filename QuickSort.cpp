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

int Partition(int A[],int low,int high)
{
	int x=A[high];
	int i=low-1;
	int j;
	for(j=low;j<high;j++)
	{
		if(A[j]<=x)
		{
			swap(A[i],A[j]);
			++i;
		}
	}
	swap(A[i+1],A[high]);
	return i+1;
}

void QuickSort(int A[],int low,int high)
{
	if(low<high)
	{
		int p=Partition(A,low,high);
		QuickSort(A,low,p-1);
		QuickSort(A,p+1,high);
	}
}
int A[10]={8,7,6,5,4,3,2,1,0};
int main()
{
	QuickSort(A,0,8);
	for(int i=0;i<9;i++)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}
