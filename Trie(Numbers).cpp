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
#define MAXN 600005
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

struct Trie
{
	Trie *left;
	Trie *right;
	int data;
}*root;

Trie* initialise()
{
	Trie* trie=new Trie;
	trie->data=-1;
	trie->left=NULL;
	trie->right=NULL;
	return trie;
}

void insert(int N)
{
	Trie* trie=root;
	for(int i=30;i>=0;i--)
	{
		if(N&(1<<i))
		{
			if(trie->right==NULL)
			{
				trie->right=initialise();
			}
			trie=trie->right;
		}
		else
		{
			if(trie->left==NULL)
			{
				trie->left=initialise();
			}
			trie=trie->left;
		}
	}
	trie->data=N;
}

LL query(int N)
{
	Trie *trie=root;
	for(int i=30;i>=0;i--)
	{
		if(N&(1<<i))
		{
			if(trie->left!=NULL)
			{
				trie=trie->left;
			}
			else
			{
				trie=trie->right;
			}
		}
		else
		{
			if(trie->right!=NULL)
			{
				trie=trie->right;
			}
			else
			{
				trie=trie->left;
			}
		}
	}
	return trie->data;
}

int A[MAXN];
int dp[MAXN];

int main()
{
	root=initialise();
	insert(0);
	
	int N;
	scanf("%d",&N);
	
	int tmp=0,maxi=0;
	
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		tmp^=A[i];
		insert(tmp);
		maxi=max(maxi,tmp^query(tmp));
		dp[i]=maxi;
	}
	
	LL sol=0;
	root=initialise();
	insert(0);
	
	tmp=0;
	maxi=0;
	
	for(int i=N-1;i>=0;i--)
	{
		tmp^=A[i];
		insert(tmp);
		maxi=max(maxi,tmp^query(tmp));
		if(i!=0)
		{
			sol=max(sol,maxi+dp[i-1]);
		}
	}
	
	printf("%d\n",sol);
	return 0;
}