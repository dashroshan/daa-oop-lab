// Write a program to check if a graph is strongly connected or not.

#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V)
    {
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int v, int w);
    bool isSC();
    Graph getTranspose();
};


void Graph::DFSUtil(int v, bool visited[])
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); i++)
        if(!visited[*i]) DFSUtil(*i,visited);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for(int v=0; v<V; v++)
    {
        list<int>::iterator i;
        for(i=adj[v].begin(); i!=adj[v].end(); i++) g.adj[*i].push_back(v);
    }
    return g;
}

bool Graph::isSC()
{
    bool visited[V];

    for(int i=0; i<V; i++)visited[i]=false;
    DFSUtil(0,visited);
    for(int i=0; i<V; i++) if(visited[i]==false)return false;

    Graph gr=getTranspose();

    for(int i=0; i<V; i++) visited[i]=false;
    gr.DFSUtil(0,visited);
    for(int i=0; i<V; i++) if(visited[i]==false) return false;

    return true;
}

int main()
{
    int n,e;
    cout<<"Enter total vertices and edges: ";
    cin>>n>>e;
    Graph g(n);
    int a,b;
    for(int i=0; i<e; i++)
    {
        cout<<"Enter edge: ";
        cin>>a>>b;
        g.addEdge(a,b);
    }
    if(g.isSC()) cout<<"The graph is strongly connected!";
    else cout<<"The graph is not strongly connected!";
    return 0;
}

/*
Enter total vertices and edges: 4 4
Enter edge: 0 1
Enter edge: 1 2
Enter edge: 2 3
Enter edge: 3 0
The graph is strongly connected!
*/
