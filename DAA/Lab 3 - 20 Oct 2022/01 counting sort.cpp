// Write a program to implement counting sort

#include <iostream>
using namespace std;

int *input(int &);
int *countingSort(int *, int);
void display(int *, int, int, string);

int main()
{
    int s, *a = input(s);
    int *b = countingSort(a, s);
    display(b, 1, s + 1, "Sorted array: ");
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

int *countingSort(int *a, int s)
{
    int *b = new int[s + 1];
    int largest = a[0];
    for (int i = 0; i < s; i++)
        if (a[i] > largest)
            largest = a[i];
    int *c = new int[largest + 1];
    for (int i = 0; i <= largest; i++)
        c[i] = 0;
    for (int i = 0; i < s; i++)
        c[a[i]] += 1;
    for (int i = 1; i <= largest; i++)
        c[i] = c[i] + c[i - 1];
    for (int i = s - 1; i >= 0; i--)
    {
        b[c[a[i]]] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
    return b;
}

/*
Enter array size: 5
Enter array elements: 1 4 2 5 3
Sorted array: 1 2 3 4 5
*/