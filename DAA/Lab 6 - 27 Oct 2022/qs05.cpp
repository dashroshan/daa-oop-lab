// Write a program to find the longest Palindromic Subsequence in the given string.

#include <iostream>
using namespace std;

int longestPalSubstr(string);

int main()
{
    string str;
    cout << "Enter string: ";
    cin>>str;
    cout << "\nLength: " << longestPalSubstr(str);
    return 0;
}

int longestPalSubstr(string str)
{
    int n = str.size(), length, maxLength = 1, start = 0, low, high;
    if (n < 2) return n;
    for (int i = 0; i < n; i++)
    {
        low = i - 1;
        high = i + 1;
        while (high < n && str[high] == str[i]) high++;
        while (low >= 0 && str[low] == str[i]) low--;
        while (low >= 0 && high < n && str[low] == str[high])
        {
            low--;
            high++;
        }

        length = high - low - 1;
        if (maxLength < length)
        {
            maxLength = length;
            start = low + 1;
        }
    }
    cout << "Longest palindrome: ";
    cout << str.substr(start, maxLength);
    return maxLength;
}

/*
Enter string: redracecarhere
Longest palindrome: racecar
Length: 7
*/
