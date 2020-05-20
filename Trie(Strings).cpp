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

const int ALPHA=26;

struct Trie
{
	Trie *child[ALPHA];
	int prefixes;
	int words;

	Trie()
	{
		prefixes=0;
		words=0;
		for(int i=0;i<ALPHA;i++)
		{
			child[i]=NULL;
		}
	}

	~Trie()
	{
		for(int i=0;i<ALPHA;i++)
		{
			delete child[i];
		}
	}

	void addWord(const char *s)
	{
		if(*s=='\0')
		{
			++words;
			return;
		}
		Trie *t=child[*s-'a'];
		if(child[*s-'a']==NULL)
		{
			t=child[*s-'a']=new Trie();
			t->prefixes=1;
		}
		else
		{
			t->prefixes=t->prefixes+1;
		}
		t->addWord(s+1);
	}

	int countPrefixes(const char *s)
	{
		if(*s=='\0')
		{
			return prefixes;
		}
		Trie *t=child[*s-'a'];
		if(t==NULL)
		{
			return 0;
		}
		return t->countPrefixes(s+1);
	}

	int countWords(const char *s)
	{
		if(*s=='\0')
		{
			return words;
		}
		Trie *t=child[*s-'a'];
		if(t==NULL)
		{
			return 0;
		}
		return t->countWords(s+1);
	}

	bool find(const char *s)
	{
		return countWords(s)>0;
	}
};

int main()
{
	Trie *trie=new Trie();
	trie->addWord("pavel");
	trie->addWord("nitin");
	trie->addWord("knbdtu");
	trie->addWord("bitchplease")
	trie->addWord("monetization");

	if(trie->find("nitin"))
	{
		cout<<"found"<<endl;
	}
	return 0;
}