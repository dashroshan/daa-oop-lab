// Write an algorithm to merge two sorted array into one sorted array.

#include <iostream>
using namespace std;

int *input(int &s);
int *mergeSorted(int *a1, int *a2, int s1, int s2);
void display(int *a, int s);

int main()
{
    int s1, s2, *a1 = input(s1), *a2 = input(s2), *a = mergeSorted(a1, a2, s1, s2);
    display(a, s1 + s2);
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

int *mergeSorted(int *a1, int *a2, int s1, int s2)
{
    int *a = new int[s1 + s2];
    int aP = 0, a1P = 0, a2P = 0;
    while (a1P < s1 && a2P < s2)
    {
        if (a1[a1P] <= a2[a2P])
            a[aP++] = a1[a1P++];
        else
            a[aP++] = a2[a2P++];
    }
    while (a1P < s1)
        a[aP++] = a1[a1P++];
    while (a2P < s2)
        a[aP++] = a2[a2P++];
    return a;
}

void display(int *a, int s)
{
    cout << "Merged array: ";
    for (int i = 0; i < s; i++)
        cout << a[i] << " ";
}

/*
Enter array size: 3
Enter elements: 2 4 9
Enter array size: 2
Enter elements: 1 5
Merged array: 1 2 4 5 9
*/