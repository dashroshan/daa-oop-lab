// Simple C++ implementation for Kruskal's
// algorithm
#include <bits/stdc++.h>
using namespace std;

int V = 0;
int *parent;

// Find set of vertex i
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Does union of i and j. It returns
// false if i and j are already in same
// set.
void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int **cost)
{
    int mincost = 0; // Cost of min MST.

    // Initialize sets of disjoint sets.
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Include minimum weight edges one by one
    int edge_count = 0;
    cout << "\nEdge \tWeight\n";
    while (edge_count < V - 1)
    {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        edge_count++;
        cout << a << " - " << b << " \t" << min << " \n";
        mincost += min;
    }
    cout << "\nWeight of MST is " << mincost;
}

int **input()
{
    int **a = new int *[V], num;
    parent = new int[V];
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

// driver program to test above function
int main()
{
    /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | /	 \ |
    (3)-------(4)
            9		 */
    cout << "Enter total vertices: ";
    cin >> V;
    int **graph = input();

    // Print the solution
    kruskalMST(graph);

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
1 - 4   5
0 - 3   6

Weight of MST is 16
*/

// O(ElogV)

/*
Create an empty set A
Make individual sets of all vertices e.g. (A),(B),(C)...
for((u,v) : edges in increasing order by weight)
    if(set containing u != set containing v)
        A = A union {(u,v)}
        Make union of both sets containing u and v
return A which contain the edges of MST
*/