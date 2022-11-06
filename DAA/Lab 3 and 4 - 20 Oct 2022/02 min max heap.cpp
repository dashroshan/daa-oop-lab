// Write a program to implement min-heap and max-heap.

#include <iostream>
#include <algorithm>
using namespace std;

int *input(int &);
void buildHeap(int *, int, bool);
void heapify(int *, int, int, bool);
void display(int *, int, int, string);

int main()
{
    int s, *a = input(s);
    buildHeap(a, s, true);
    display(a, 1, s, "Max heap: ");
    buildHeap(a, s, false);
    display(a, 1, s, "Min heap: ");
    return 0;
}

void display(int *a, int b, int s, string text)
{
    cout << text;
    for (int i = b; i < s; i++)
        cout << a[i] << " ";
    cout << endl;
}

int *input(int &size)
{
    cout << "Enter heap array length: ";
    cin >> size;
    cout << "Enter array elements: ";
    int *arr = new int[++size];
    arr[0] = 0;
    for (int i = 1; i < size; i++)
        cin >> arr[i];
    return arr;
}

void heapify(int *a, int i, int hs, bool isMax)
{
    int l = 2 * i, r = 2 * i + 1, value = i;
    if (l <= hs && (isMax ? (a[l] > a[i]) : (a[l] < a[i])))
        value = l;
    if (r <= hs && (isMax ? (a[r] > a[value]) : (a[r] < a[value])))
        value = r;
    if (value != i)
    {
        swap(a[i], a[value]);
        heapify(a, value, hs, isMax);
    }
}

void buildHeap(int *a, int s, bool isMax)
{
    for (int i = s / 2; i >= 1; i--)
        heapify(a, i, s - 1, isMax);
}

/*
Enter heap array length: 11
Enter array elements: 1 3 5 4 6 13 10 9 8 15 17
Max heap: 17 15 13 9 6 5 10 4 8 3 1
Min heap: 1 3 5 4 6 13 10 9 8 15 17
*/
