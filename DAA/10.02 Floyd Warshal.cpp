// Write a program to implement Floyd�s algorithm for the all pairs shortest path problem.

#include <iostream>
using namespace std;

int **input(int *);
void display(int **, int);
void floydWarshall(int **, int);

int main()
{
    int v, **g = input(&v);
    floydWarshall(g, v);
    display(g, v);
    return 0;
}

int **input(int *v)
{
    cout << "Enter total vertices: ";
    cin >> *v;
    cout << "Enter the adjacency matrix (0 for i to i, -1 for infinity):\n";
    int **matrix = new int *[*v], i, j;
    for (i = 0; i < *v; i++)
    {
        matrix[i] = new int[*v];
        for (j = 0; j < *v; j++)
            cin >> matrix[i][j];
    }
    return matrix;
}

void display(int **g, int v)
{
    int i, j;
    cout << "\nAll pairs shortest path matrix:\n";
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}

void floydWarshall(int **g, int v)
{
    int i, j, k;
    for (k = 0; k < v; k++)
    {
        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)
            {
                int oldPath = g[i][j];
                int newPath = g[i][k] + g[k][j];
                if (oldPath == -1 && (g[i][k] == -1 || g[k][j] == -1))
                    g[i][j] = -1;
                else if (oldPath == -1)
                    g[i][j] = newPath;
                else if ((g[i][k] == -1 || g[k][j] == -1))
                    g[i][j] = oldPath;
                else
                    g[i][j] = (newPath < oldPath) ? newPath : oldPath;
            }
        }
    }
}

/*
Enter total vertices: 4
Enter the adjacency matrix (0 for i to i, -1 for infinity):
0 3 -1 7
8 0 2 -1
5 -1 0 1
2 -1 -1 0

All pairs shortest path matrix:
0 3 5 6
5 0 2 3
3 6 0 1
2 5 7 0
*/

// O(v^3)

/*
for(k=0 to v-1)
for(i=0 to v-1)
for(j=0 to v-1)
Gij = min(Gij, Gik + Gkj)
*/