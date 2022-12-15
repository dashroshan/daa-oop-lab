// From a given vertex in a weighted connected graph,
// find shortest paths to other vertices using Dijkstra's algorithm.

#include <bits/stdc++.h>
using namespace std;

int V;
void dijkstra(int);
list<pair<int, int>> *adj;
typedef pair<int, int> iPair;

int main()
{
    int e, u, v, w;
    cout << "Enter total vertices and edges: ";
    cin >> V >> e;
    adj = new list<iPair>[V];
    cout << "Enter start, end, and weight of " << e << " edges:\n";
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    cout << "\nEnter source vertex: ";
    cin >> u;
    dijkstra(u);
    return 0;
}

void dijkstra(int src)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex: Distance from source\n");
    for (int i = 0; i < V; ++i)
        cout << i << "     : " << dist[i] << endl;
}

/*
Enter total vertices and edges: 4 5
Enter start, end, and weight of 5 edges:
0 1 5
0 2 1
0 3 2
1 2 2
2 3 3

Enter source vertex: 0
Vertex: Distance from source
0     : 0
1     : 3
2     : 1
3     : 2
*/

// O(ElogV)

/*
Create an empty set S to store finalized vertices.
Initialize source vertex to 0 and rest of vertices to infinity.
Create a priority queue Q=vertices of graph.
while(Q!=empty)
    u=extractMin(Q)
    S=S union u
    for(v : all adjacent vertices of u)
        if(u + edge(u,v) < v)
            v = u + edge(u,v)
*/

/*
Create an empty set S to store finalized vertices.
Initialize source vertex to 0 and rest of vertices to infinity.
while(S doesnot include all the vertices)
    u=minimum weight vertex not included in S
    S=S union u
    for(v : all adjacent vertices of u)
        if(u + edge(u,v) < v)
            v = u + edge(u,v)
*/