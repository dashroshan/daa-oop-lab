// Find the longest common subsequence of 2 strings

#include <iostream>
#include <algorithm>
using namespace std;

void lcs(string, string);

int main()
{
    string s1, s2;
    cout << "Enter 1st string: ";
    cin >> s1;
    cout << "Enter 2nd string: ";
    cin >> s2;
    lcs(s1, s2);
    return 0;
}

void lcs(string X, string Y)
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

    int index = L[m][n];

    // Create a character array to store the lcs string
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the terminating character

    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1]; // Put current character in result
            i--;
            j--;
            index--; // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the lcs
    cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

/*
Enter 1st string: stone
Enter 2nd string: longest
LCS of stone and longest is one
*/