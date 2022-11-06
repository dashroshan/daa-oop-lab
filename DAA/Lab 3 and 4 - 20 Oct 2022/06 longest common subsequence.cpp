// Find the longest common subsequence of 2 strings

#include <iostream>
#include <algorithm>
using namespace std;

int lcs(string, string);

int main()
{
    string s1, s2;
    cout << "Enter 1st string: ";
    cin >> s1;
    cout << "Enter 2nd string: ";
    cin >> s2;
    printf("Length of LCS is %d\n", lcs(s1, s2));
    return 0;
}

int lcs(string X, string Y)
{
    int m = X.length(), n = Y.length(), L[m + 1][n + 1], i, j;
    for (i = 0; i <= m; i++)
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    return L[m][n];
}

/*
Enter 1st string: stone
Enter 1st string: longest
Length of LCS is 3
*/