/*Given an array of strings, find if the strings can be chained to form a circle*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> v[N];
vector<int>Tv[N];
bool visited[N];
int in[N];
int V;
void addEdge(int L, int R)
{
	v[L].push_back(R);
	//v[R].push_back(L);
}

void trans()
{
	for (int i = 0; i < V; i++)
	{
		for (auto j : v[i])
		{
			Tv[j].push_back(i);
			in[j]++;     //finding the indegree of node !! 
		}
	}
}
void dfs1(int node)
{
	visited[node] = 1;
	for (auto i : v[node])
	{
		if (!visited[i])
		{	
			dfs1(i);
		}
	}
}
void dfs2(int node)
{
	visited[node] = 1;
	for (auto i : Tv[node])
	{
		if (!visited[i])
		{
			dfs2(i);
		}
	}
}
bool isScc()
{
	//kosaraju  algo
	dfs1(0);
	for (int i = 0; i < V; i++)
		if (visited[i] == false)return false;
	trans();
	memset(visited, 0, sizeof visited);
	dfs2(0);
	for (int i = 0; i < V; i++)
		if (visited[i] == false)return false;
	return true;
}
bool isEulerianCycle()
{
	//Rule 1: isScc ?
	if (!isScc())return false;
	//Rule 2: indegree == outdegree ?
	for (int i = 0; i < V; i++)
		if (v[i].size() != in[i])
			return false;
	return true;
}
int main()
{
	V = 5;
	g.addEdge(1, 0);  // L = starting character R= ending character !!!
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);

	if (isEulerianCycle())
		cout << "Given directed graph is eulerian \n";
	else
		cout << "Given directed graph is NOT eulerian \n";

}