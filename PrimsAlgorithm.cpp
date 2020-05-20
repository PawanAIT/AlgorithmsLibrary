#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
using namespace std;

int main()
{
    int N;
    cout<<"Enter the number of vertices :-";
    cin>>N;

    vector<pair<int,int> > G[N+1];
    int M;

    cout<<"Enter the number of edges :-";
    cin>>M;

    cout<<"Enter two vertices for which an edge exists between them :-\n";

    for(int i=0;i<M;i++)
    {
        int U,V,W;
        cin>>U>>V>>W;
        G[U].push_back(make_pair(V,W));
        G[V].push_back(make_pair(U,W));
    }

    int S;
    cout<<"Enter the source node :-";
    cin>>S;

    set<pair<int,int> > PQ;

    vector<int> parent(N+1,-1);
    vector<int> dist(N+1,123456789);
    vector<bool> visited(N+1,false);

    dist[S]=0;

    for(int i=1;i<=N;i++)
    {
        PQ.insert(make_pair(dist[i],i));
    }
    vector<pair<int,int> > MST_edges;
    int total_cost=0;
    while(!PQ.empty())
    {
        pair<int,int> H=*PQ.begin();
        PQ.erase(PQ.begin());
        visited[H.second]=true;

        if(H.second!=S)
        {
            MST_edges.push_back(make_pair(parent[H.second],H.second));
        }

        for(int i=0;i<G[H.second].size();i++)
        {
            if(visited[G[H.second][i].first]==false)
            {
                if(dist[G[H.second][i].first]>G[H.second][i].second)
                {
                    PQ.erase(PQ.find(make_pair(dist[G[H.second][i].first],G[H.second][i].first)));
                    dist[G[H.second][i].first]=G[H.second][i].second;
                    PQ.insert(make_pair(dist[G[H.second][i].first],G[H.second][i].first));
                    parent[G[H.second][i].first]=H.second;
                }
            }
        }
    }

    cout<<"The edge set of MST formed using Prims Algorithm is :-\n";

    for(int i=0;i<MST_edges.size();i++)
    {
        cout<<MST_edges[i].first<<" "<<MST_edges[i].second<<endl;
    }

    for(int i=1;i<=N;i++)
    {
        if(dist[i]!=123456789)
        {
            total_cost+=dist[i];
        }
    }
    cout<<"Total cost of constructing MST using Prims Algorithm is :- "<<total_cost<<endl;
    return 0;
}
