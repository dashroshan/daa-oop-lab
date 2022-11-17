// Implement Matrix Chain Multiplication.

#include <iostream>
#include <algorithm>
using namespace std;

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

void printParenthesis(int i, int j, int n, int *bracket, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    cout << ")";
}

void matrixChainOrder(int p[], int n)
{
    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name = 'A';

    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n - 1, n, (int *)bracket, name);
    cout << "\nOptimal Cost is : " << m[1][n - 1];
}

int main()
{
    int n, *arr = input(n);
    matrixChainOrder(arr, n);
    return 0;
}

/*
Total matrices: 3
Enter 4 dimensions (skip consecutive matrix dimension i.e. A2,3 x A3,4 as 2 3 4): 2 3 4 2
Optimal Parenthesization is : (A(BC))
Optimal Cost is : 36
*/
