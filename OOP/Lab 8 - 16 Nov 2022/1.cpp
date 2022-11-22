#include <iostream>
using namespace std;

template <typename t>
void swapAny(t &a, t &b)
{
    t temp = a;
    a = b;
    b = temp;
}

int main()
{
    int i1, i2;
    char c1, c2;
    cout << "Enter 2 integers and 2 characters: ";
    cin >> i1 >> i2 >> c1 >> c2;
    swapAny(i1, i2);
    swapAny(c1, c2);
    cout << "Swapped integers: " << i1 << " " << i2 << endl
         << "Swapped characters: " << c1 << " " << c2;
    return 0;
}

/*
Enter 2 integers and 2 characters: 1 2 a b
Swapped integers: 2 1
Swapped characters: b a
*/