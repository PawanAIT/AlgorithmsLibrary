#include <bits/stdc++.h>
using namespace std;
int n,e,u,v;
const int N=1e5+5;
int visited[N],low[N],used[N];
std::vector<int> G[N];
int Time=0;
stack<int> st;
void dfs(int x)
{
    visited[x]=low[x]=++Time;
    st.push(x);
    for(auto &i:G[x])
        if(!used[i])
        {
            if(!visited[i])
            {
                dfs(i);
                low[x] = min(low[x],low[i]); 
            }
            else
                low[x]=min(low[x],visited[i]);
        }

    if(low[x]==visited[x])
    {
        while(x!=st.top()){
            v=st.top();
            st.pop();
            used[v]=1;
            printf("%d ",v);
        }
        printf("%d,",x);
        used[x]=1;
        st.pop();
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&e);
        memset(visited,0,sizeof(visited));
        memset(used,0,sizeof(used));
        memset(low,0,sizeof(low));
        while(!st.empty())st.pop();
        for (int i = 0; i < 106; ++i)
            G[i].clear();
        
        for (int i = 0; i < e; ++i)
            scanf("%d%d",&u,&v),G[u].push_back(v);
        for (int i = 0; i < n; ++i)
           if(!visited[i])
            dfs(i);
        printf("\n");
    }
    return 0;
}

/*
1
5 6
1 2 2 3 3 4 4 1 3 5 5 2

*/

