// Write the program the following operations of the matrix
// a) Addition   b) Multiplication   c) Transpose

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int **input(int &m, int &n);
void display(int **a, int m, int n, string s);
int **add(int m, int n, int **a1, int **a2);
int **multiply(int m1, int n1, int m2, int n2, int **a1, int **a2);
int **transpose(int m, int n, int **aa);

int main()
{
    int m1, n1, **a1 = input(m1, n1), m2, n2, **a2 = input(m2, n2), m, n, **a;
    char c;
    system("cls");
loop:
    cout << "\n\n(a)Addition\n(b)Multiplication\n(c)Transpose\n\nEnter choice: ";
    cin >> c;
    system("cls");
    switch (c)
    {
    case 'a':
        if (m1 == m2 && n1 == n2)
        {
            a = add(m1, n1, a1, a2);
            display(a, m1, n1, "Addition Matrix:\n");
        }
        else
            cout << "Matrices cannot be added!";
        goto loop;
    case 'b':
        if (n1 == m2)
        {
            a = multiply(m1, n1, m2, n2, a1, a2);
            display(a, m1, n2, "Multiplication Matrix:\n");
        }
        else
            cout << "Matrices cannot be multiplied!";
        goto loop;
    case 'c':
        if (m1 == n1)
        {
            a = transpose(m1, n1, a1);
            display(a, m1, n1, "Transpose of Matrix 1:\n");
        }
        else
            cout << "Transpose not possible for Matrix 1!";
        if (m2 == n2)
        {
            a = transpose(m2, n2, a2);
            display(a, m2, n2, "\nTranspose of Matrix 2:\n");
        }
        else
            cout << "Transpose not possible for Matrix 2!";
        goto loop;
    }
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

void display(int **a, int m, int n, string s)
{
    cout << s;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << left << a[i][j];
        cout << "\n";
    }
}

int **add(int m, int n, int **a1, int **a2)
{
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            a[i][j] = a1[i][j] + a2[i][j];
    }
    return a;
}

int **multiply(int m1, int n1, int m2, int n2, int **a1, int **a2)
{
    int **a = new int *[m1];
    for (int i = 0; i < m1; i++)
    {
        a[i] = new int[n2];
        for (int j = 0; j < n2; j++)
        {
            a[i][j] = 0;
            for (int k = 0; k < m1; k++)
                a[i][j] += a1[i][k] * a2[k][j];
        }
    }
    return a;
}

int **transpose(int m, int n, int **aa)
{
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            a[i][j] = aa[j][i];
    }
    return a;
}
