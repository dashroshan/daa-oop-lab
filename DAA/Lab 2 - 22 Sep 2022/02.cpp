// Implement the quick sort algorithm

#include <iostream>
using namespace std;

int *input(int &);
void display(int *, int, string);
void swap(int &, int &);
void quickSort(int *, int, int);

int main()
{
    int s, *a = input(s);
    display(a, s, "\nBefore sorting: ");
    quickSort(a, 0, s - 1);
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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int *array, int low, int high)
{
    if (low >= high)
        return;
    int i = low, j = high, pivot = array[low];
    while (j > i)
    {
        while ((pivot >= array[i]) && i <= high)
            i++;
        while ((pivot < array[j]) && j >= low)
            j--;
        if (j > i)
            swap(array[i], array[j]);
    }
    swap(array[j], array[low]);
    quickSort(array, low, j - 1);
    quickSort(array, j + 1, high);
}

/*
Enter array size: 5
Enter elements: 5 1 4 2 3

Before sorting: 5 1 4 2 3
After  sorting: 1 2 3 4 5
*/