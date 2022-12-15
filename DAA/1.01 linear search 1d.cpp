// Write an algorithm to search an element in the array using Linear Search.

#include <iostream>
using namespace std;

int *input(int &s);
int linearSearch(int *a, int s, int e);

int main()
{
    int s, *a = input(s), e, index;
    cout << "Enter element to search: ";
    cin >> e;
    index = linearSearch(a, s, e);
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

int linearSearch(int *a, int s, int e)
{
    for (int i = 0; i < s; i++)
        if (a[i] == e)
            return i;
    return -1;
}

/*
Enter array size: 5
Enter elements: 1 2 3 4 5
Enter element to search: 4
Element found at index 3 of the array!
*/