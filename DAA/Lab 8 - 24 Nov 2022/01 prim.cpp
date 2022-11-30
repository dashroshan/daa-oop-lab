#include <bits/stdc++.h>
using namespace std;

int V = 0;

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int **graph)
{
    int wt = 0;
    cout << "\nEdge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
        wt += graph[i][parent[i]];
    }
    cout << "\nWeight of MST is " << wt;
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int **graph)
{
    // Array to store constructed MST
    int parent[V];

    // Key values used to pick minimum weight edge in cut
    int key[V];

    // To represent set of vertices included in MST
    bool mstSet[V];

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    printMST(parent, graph);
}

int **input()
{
    int **a = new int *[V], num;
    cout << "Enter " << V << "x" << V << " adjecency matrix (-1 for infinity):\n";
    for (int i = 0; i < V; i++)
    {
        a[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            cin >> num;
            a[i][j] = (num == -1) ? INT_MAX : num;
        }
    }
    return a;
}

// Driver's code
int main()
{
    cout << "Enter total vertices: ";
    cin >> V;
    int **graph = input();
    primMST(graph);

    return 0;
}

/*
Enter total vertices: 5
Enter 5x5 adjecency matrix (-1 for infinity):
0 2 -1 6 -1
2 0 3 8 5
-1 3 0 -1 7
6 8 -1 0 9
-1 5 7 9 0

Edge    Weight
0 - 1   2
1 - 2   3
0 - 3   6
1 - 4   5

Weight of MST is 16
*/