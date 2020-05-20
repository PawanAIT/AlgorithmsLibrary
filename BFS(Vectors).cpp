#include<bits/stdc++.h>
using namespace std;

vector <int> graph[100];
int n,m,v,u;
bool visited[100];

void BFS(int p)
{
	for(int i = 0; i < n; i ++)
        visited[i] = false;
    queue <int> q;
    q.push(p);
    while(!q.empty())
    {
        int curr = q.front();
        cout<<curr<<" ";
        visited[curr] = true;
        q.pop();
        for(int i = 0; i < graph[curr].size(); i ++)
        {
            if(!visited[graph[curr][i]])
            {
                q.push(graph[curr][i]);
                visited[graph[curr][i]] = true;
            }
        }
    }
}

int main()
{
    scanf(" %d %d", &n, &m);
    for(int i = 0; i < m; i ++)
    {
        scanf(" %d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    BFS(2);
    return 0;
}
