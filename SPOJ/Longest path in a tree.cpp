#include "bits/stdc++.h"
#define ll __int64
using namespace std;
std::vector<int> v[100005];
int visited[100005];
int main()
{    
    ios::sync_with_stdio(0); cin.tie(0);
    int t,x,y;
    cin>>t;
    for (int i = 0; i < t-1; ++i)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
 
    queue<int>q;
    q.push(x);
    visited[x]=1;
    int ans=0;
    int temp;
    int index=0;
   while(!q.empty())
    {
 
        temp=q.front();
        //cout<<temp<<endl;
        q.pop();
        for (int i = 0; i < v[temp].size(); ++i)
        {
           if(!visited[v[temp][i]]){
            visited[v[temp][i]]=visited[temp]+1;
            q.push(v[temp][i]);
            if (ans<visited[v[temp][i]])
            {
                ans=visited[v[temp][i]];
                index=v[temp][i];
            }
           }
        }
    }
 
memset(visited,0,sizeof(visited));
 
q.push(index);
 
while(!q.empty())
{
     temp=q.front();
        //cout<<temp<<endl;
        q.pop();
        for (int i = 0; i < v[temp].size(); ++i)
        {
           if(!visited[v[temp][i]]){
            visited[v[temp][i]]=visited[temp]+1;
            q.push(v[temp][i]);
            if (ans<visited[v[temp][i]])
            {
                ans=visited[v[temp][i]];
                index=v[temp][i];
            }
           }
        }
}
 
cout<<ans;
   
     
    return 0;
} 
