// Find the mean and median of an unsorted array

#include <iostream>
#include <algorithm>
using namespace std;

int *input(int &);
double mean(int *, int);
double median(int *, int);

int main()
{
    int s, *a = input(s);
    cout << "Median: " << median(a, s) << "\n"
         << "Mean: " << mean(a, s);
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

double mean(int *a, int s)
{
    double m = 0.0;
    for (int i = 0; i < s; i++)
        m += a[i];
    return m / s;
}

double median(int *a, int s)
{
    sort(a, a + s);
    if (s % 2 == 1)
        return a[s / 2];
    else
        return (a[s / 2] + a[s / 2 - 1]) / 2.0;
}

/*
Enter array size: 4
Enter elements: 8 7 1 5
Median: 6
Mean: 5.25
*/