// Write a program to implement bubble sort.

#include <iostream>
using namespace std;

int *input(int &);
void bubbleSort(int *, int);
void display(int *, int, int, string);

int main()
{
    int s, *a = input(s);
    bubbleSort(a, s);
    display(a, 0, s, "Sorted array: ");
    return 0;
}

int *input(int &size)
{
    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter array elements: ";
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    return arr;
}

void display(int *a, int b, int s, string text)
{
    cout << text;
    for (int i = b; i < s; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bubbleSort(int *a, int s)
{
    for (int i = 0; i < s; i++)
        for (int i = 1; i < s; i++)
            if (a[i] < a[i - 1])
            {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
            }
}

/*
Enter array size: 5
Enter array elements: 2 1 3 5 4
Sorted array: 1 2 3 4 5
*/