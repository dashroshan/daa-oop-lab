// Write a program to implement bucket sort.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double *input(int &);
void bucketSort(double *, int, int);
void display(double *, int, int, string);

int main()
{
    int s;
    double *a = input(s);
    bucketSort(a, s, 10);
    display(a, 0, s, "Sorted array: ");
    return 0;
}

double *input(int &size)
{
    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter array elements: ";
    double *arr = new double[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    return arr;
}

void display(double *a, int b, int s, string text)
{
    cout << text;
    for (int i = b; i < s; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bucketSort(double *a, int s, int n)
{
    vector<double> b[n];
    int index = 0;
    for (int i = 0; i < s; i++)
        b[int(n * a[i])].push_back(a[i]);
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            a[index++] = b[i][j];
}

/*
Enter array size: 5
Enter array elements: 0.3 0.1 0.9 0.2 0.7
Sorted array: 0.1 0.2 0.3 0.7 0.9
*/