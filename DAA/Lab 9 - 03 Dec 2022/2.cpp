// Write a program to implement Depth First Search (DFS) graph traversal methods.

#include <bits/stdc++.h>
using namespace std;

void edge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u]=true;
    cout<< u<< " ";
    for(int i=0; i<adj[u].size(); i++)
        if(visited[adj[u][i]]==false ) DFSUtil(adj[u][i],adj,visited);
}

void DFS(vector<int> adj[],int V)
{
    vector<bool> visited(V,false);
    for(int u=0; u<V; u++)
        if(visited[u]==false)
            DFSUtil(u,adj,visited);
}

int main()
{
    int n,e;
    cout<<"Enter total vertices and edges: ";
    cin>>n>>e;
    vector <int> adj[n];
    int a,b;
    for(int i=0; i<e; i++)
    {
        cout<<"Enter edge: ";
        cin>>a>>b;
        edge(adj,a,b);
    }
    cout<<"DFS: ";
    DFS(adj,n);
    return 0;
}

/*
Enter total vertices and edges: 5 6
Enter edge: 0 1
Enter edge: 0 2
Enter edge: 0 4
Enter edge: 1 3
Enter edge: 2 4
Enter edge: 3 4
DFS: 0 1 3 4 2
*/
