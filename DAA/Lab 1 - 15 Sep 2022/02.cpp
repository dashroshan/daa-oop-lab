// Write an algorithm to search an element in the 2-Dimensional array using Linear Search.

#include <iostream>
using namespace std;

int **input(int &m, int &n);
int *linearSearch(int **a, int m, int n, int e);

int main()
{
    int m, n, **a = input(m, n), e, *index;
    cout << "Enter element to search: ";
    cin >> e;
    index = linearSearch(a, m, n, e);
    if (index[0] == -1)
        cout << "Element not found in the 2D array!";
    else
        cout << "Element found at location (" << index[0] << ", " << index[1] << ") of the array!";
    return 0;
}

int **input(int &m, int &n)
{
    cout << "Enter 2D array size: ";
    cin >> m >> n;
    int **a = new int *[m];
    cout << "Enter elements:\n";
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    return a;
}

int *linearSearch(int **a, int m, int n, int e)
{
    int *ans = new int[2];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == e)
            {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
    ans[0] = -1;
    ans[1] = -1;
    return ans;
}

/*
Enter 2D array size: 2 2
Enter elements:
1 2
3 4
Enter element to search: 3
Element found at location (1, 0) of the array!
*/