// Write a program to find the longest Palindromic Subsequence in the given string.

#include <iostream>
#include <algorithm>
using namespace std;

string lcs(string X, string Y)
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
    return lcs;
}

string longestPal(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return lcs(str, rev);
}

int main()
{
    string str;
    cout << "Enter string: ";
    cin >> str;
    cout << "\nLongest palindrome: " << longestPal(str);
    return 0;
}

/*
Enter string: abcbd
Longest palindrome: bcb
*/

// O(N^2) where N=string length

/*
longest palindrome = lcs(string, reverse(string))
*/