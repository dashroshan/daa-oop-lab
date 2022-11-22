#include <iostream>
using namespace std;

template <typename t>
void sortAsc(t *a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            if (a[j - 1] > a[j])
            {
                t temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int ia[n];
    char ca[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
        cin >> ia[i];
    cout << "Enter " << n << " characters: ";
    for (int i = 0; i < n; i++)
        cin >> ca[i];
    sortAsc(ia, n);
    sortAsc(ca, n);
    cout << "\nSorted integer array: ";
    for (int i = 0; i < n; i++)
        cout << ia[i] << " ";
    cout << "\nSorted character array: ";
    for (int i = 0; i < n; i++)
        cout << ca[i] << " ";
    return 0;
}

/*
Enter size of array: 3
Enter 3 integers: 3 1 2
Enter 3 characters: b a c

Sorted integer array: 1 2 3
Sorted character array: a b c
*/