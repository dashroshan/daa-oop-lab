#include <iostream>
#include "qs1asc.h";
#include "qs1dsc.h";
using namespace std;

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int a[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    asc::sortInt(a, n);
    cout << "\nSorted in ascending order: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    dsc::sortInt(a, n);
    cout << "\nSorted in descending order: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}