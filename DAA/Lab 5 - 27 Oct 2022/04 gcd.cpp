// Find GCD of 2 numbers using Euclidean algorithm

#include <iostream>
using namespace std;

int gcd(int, int);

int main()
{
    int a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;
    cout << "GCD of the entered numbers: " << gcd(a, b);
    return 0;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

/*
Enter 2 numbers: 18 24
GCD of the entered numbers: 6
*/
