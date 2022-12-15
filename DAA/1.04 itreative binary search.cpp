// Write an algorithm to search an element in the array using iterative Binary Search.

#include <iostream>
using namespace std;

int *input(int &s);
int binarySearch(int *a, int s, int e);

int main()
{
    int s, *a = input(s), e, index;
    cout << "Enter element to search: ";
    cin >> e;
    index = binarySearch(a, s, e);
    if (index == -1)
        cout << "Element not found in the array!";
    else
        cout << "Element found at index " << index << " of the array!";
    return 0;
}

int *input(int &s)
{
    cout << "Enter array size: ";
    cin >> s;
    int *a = new int[s];
    cout << "Enter elements: ";
    for (int i = 0; i < s; i++)
        cin >> a[i];
    return a;
}

int binarySearch(int *a, int s, int e)
{
    int l = 0, h = s - 1, m;
    while (l < h)
    {
        m = (l + h) / 2;
        if (a[m] == e)
            return m;
        else if (a[m] > e)
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
