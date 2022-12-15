// Write a program to implement Breadth First Search (BFS) graph traversal methods.

#include <bits/stdc++.h>
using namespace std;

vector<bool> v;
vector<vector<int>> g;

void edge(int a, int b)
{
    g[a].push_back(b);
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    v[u] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << " ";
        for (vector<int>::iterator i = g[f].begin(); i != g[f].end(); i++)
        {
            if (!v[*i])
            {
                q.push(*i);
                v[*i] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter total vertices and edges: ";
    cin >> n >> e;
    v.assign(n, false);
    g.assign(n, vector<int>());
    int a, b;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter edge: ";
        cin >> a >> b;
        edge(a, b);
    }
    cout << "BFS: ";
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
            bfs(i);
    }
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
BFS: 0 1 2 4 3
*/

// O(V+E)

/*
Create a queue and insert the starting vertex.
Create a visited array [{vertex: visitedBoolean}...] and set all as unvisited i.e. false
While(queue is not empty)
    remove a vertex from queue
    set its visited to true
    print it to BFS
    add all its adjacent unvisited vertices to queue
*/