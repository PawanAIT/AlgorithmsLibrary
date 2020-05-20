#include "bits/stdc++.h"
#define ll __int64
using namespace std;
int N;
 
void bfs()
{
	int visited[20005]={0};
    queue<pair<string,int> > Q;
    Q.push({"1",1});
    int x;
    pair<string,int> T;
    while(!Q.empty())
    {
        T=Q.front();
        x=T.second;
        Q.pop();
        if (x%N==0)
        {
            cout<<T.first<<endl;
            return;
        }
        if (!visited[x%N]) // cutting the branches with same remainder ..!
        {
            visited[x]=1;
            Q.push({T.first+'0',(10*x)%N});
            Q.push({T.first+'1',(10*x+1)%N});
        }
    }
}
 
int main()
{    
    //ios::sync_with_stdio(0); cin.tie(0);
    int t;
    scanf("%d",&t);
    for (int i = 0; i < t; ++i)
    {
       scanf("%d",&N);
        bfs();
    }
 
     
    return 0;
} 
