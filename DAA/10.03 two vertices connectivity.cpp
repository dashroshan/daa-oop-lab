// Write a program to use the BFS algorithm to check the connectivity
// between any two vertices in the graph efficiently.

#include <iostream>
#include <list>
using namespace std;

int V;
list<int> *adj;
bool isReachable(int, int);

int main()
{
    int e, a, b;
    cout << "Enter total vertices and edges: ";
    cin >> V >> e;
    adj = new list<int>[V];

    for (int i = 0; i < e; i++)
    {
        cout << "Enter edge: ";
        cin >> a >> b;
        adj[a].push_back(b);
    }

    cout << "\nEnter 2 vertices to check connectivity: ";
    cin >> a >> b;
    bool a2b = isReachable(a, b), b2a = isReachable(b, a);
    cout << a << " to " << b << (a2b ? ": connected" : ": not connected") << endl
         << b << " to " << a << (b2a ? ": connected" : ": not connected") << endl;
    return 0;
}

bool isReachable(int s, int d)
{
    if (s == d)
        return true;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (*i == d)
                return true;
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return false;
}

/*
Enter total vertices and edges: 4 4
Enter edge: 0 1
Enter edge: 0 2
Enter edge: 1 2
Enter edge: 2 3

Enter 2 vertices to check connectivity: 1 3
1 to 3: connected
3 to 1: not connected
*/

// O(V+E)

/*
Run BFS or DFS with starting vertex as one of the 2 vertices.
If the 2nd vertex is there in the search, both vertices are connected.
*/