// Implement the merge sort algorithm

#include <iostream>
using namespace std;

int *input(int &);
void display(int *, int, string);
void mergeSort(int *, int, int);

int main()
{
    int s, *a = input(s);
    display(a, s, "\nBefore sorting: ");
    mergeSort(a, 0, s - 1);
    display(a, s, "\nAfter  sorting: ");
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

void display(int *a, int s, string text)
{
    cout << text;
    for (int i = 0; i < s; i++)
        cout << a[i] << " ";
}

void mergeSort(int *array, int low, int high)
{
    if (low >= high)
        return;
    int mid = (high + low) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);

    int ls = mid - low + 1, rs = high - mid, left[ls], right[rs];
    for (int i = 0; i < ls; i++)
        left[i] = array[low + i];
    for (int i = 0; i < rs; i++)
        right[i] = array[mid + i + 1];

    int li = 0, ri = 0, ai = low;
    while (li < ls && ri < rs)
    {
        if (left[li] <= right[ri])
        {
            array[ai] = left[li];
            li++;
        }
        else
        {
            array[ai] = right[ri];
            ri++;
        }
        ai++;
    }

    while (li < ls)
    {
        array[ai] = left[li];
        li++;
        ai++;
    }

    while (ri < rs)
    {
        array[ai] = right[ri];
        ri++;
        ai++;
    }
}

/*
Enter array size: 5
Enter elements: 5 1 4 2 3

Before sorting: 5 1 4 2 3
After  sorting: 1 2 3 4 5
*/