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
#define MAXN 1000500
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

struct node
{
	int next[26];
	int len;
	int sufflink;
	int num;
};

int len;
char str[MAXN];
node tree[MAXN];
int num;		// node 1 - root with len -1, node 2 - root with len 0
int suff;		// max suffix palindrome
LL ans;

bool addLetter(int pos)
{
	int cur=suff,curlen=0;
	int let=str[pos]-'a';
	
	while(true)
	{
		curlen=tree[cur].len;
		if((pos-1-curlen>=0)&&(str[pos-1-curlen]==str[pos]))
		{
			break;
		}
		cur=tree[cur].sufflink;
	}
	
	if(tree[cur].next[let])
	{
		suff=tree[cur].next[let];
		return false;
	}
	
	num++;
	suff=num;
	tree[num].len=tree[cur].len+2;
	tree[cur].next[let]=num;
	
	if(tree[num].len==1)
	{
		tree[num].sufflink=2;
		tree[num].num=1;
		return true;
	}
	
	while(true)
	{
		cur=tree[cur].sufflink;
		curlen=tree[cur].len;
		if((pos-1-curlen)>=0&&(str[pos-1-curlen]==str[pos]))
		{
			tree[num].sufflink=tree[cur].next[let];
			break;
		}
	}
	
	tree[num].num=1+tree[tree[num].sufflink].num;
	return true;
}

void initPalindromeTree()
{
	num=2;
	suff=2;
	tree[1].len=-1;
	tree[1].sufflink=1;
	tree[2].len=0;
	tree[2].sufflink=1;
}

int main() 
{
	gets(str);
	len=strlen(str);
	
	initPalindromeTree();
	//ans counts the number of total palindromes
	for(int i=0;i<len;i++)
	{
		addLetter(i);
		ans+=tree[suff].num;
	}
	cout<<ans<<endl;
	return 0;
}