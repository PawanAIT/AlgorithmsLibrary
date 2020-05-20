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

void insert_bottom(stack<int> &S,int item)
{
    int temp;
    if(S.empty())
    {
        S.push(item);
    }
    else
    {
        temp=S.top();
        S.pop();
        insert_bottom(S,item);
        S.push(temp);
    }
}
void reverseStack(stack<int> S)
{
    int temp;
	if(!S.empty())
	{
		temp=S.top();
		S.pop();
		//cout<<temp<<endl;
		reverseStack(S);
		insert_bottom(S,temp);
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	stack<int> S;
	for(int i=0;i<N;i++)
	{
		int X;
		scanf("%d",&X);
		S.push(X);
	}

	reverseStack(S);

	while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }
	return 0;
}
