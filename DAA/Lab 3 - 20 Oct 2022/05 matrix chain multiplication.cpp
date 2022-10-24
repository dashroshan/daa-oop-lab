// Implement Matrix Chain Multiplication.

#include <iostream>
#include <algorithm>
using namespace std;

int *input(int &);
int MatrixChain(int[], int, int);

int main()
{
    int n, *arr = input(n);
    cout << "Minimum number of multiplications: " << MatrixChain(arr, 1, n - 1);
    return 0;
}

int *input(int &size)
{
    cout << "Total matrices: ";
    cin >> size;
    size++;
    cout << "Enter " << size << " dimensions (skip consecutive matrix dimension i.e. A2,3 x A3,4 as 2 3 4): ";
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    return arr;
}

int MatrixChain(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k, count, mini = INT_MAX;
    for (k = i; k < j; k++)
    {
        count = MatrixChain(p, i, k) + MatrixChain(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        mini = min(count, mini);
    }
    return mini;
}

/*
Total matrices: 3
Enter 4 dimensions (skip consecutive matrix dimension i.e. A2,3 x A3,4 as 2 3 4): 2 3 4 2
Minimum number of multiplications: 36
*/
