#include <iostream>
using namespace std;

template <typename t>
void print(t n)
{
    cout << "Generic: " << n << endl;
}

void print(int n)
{
    cout << "Specific: " << n << endl;
}

int main()

{
    int i;
    double d;
    cout << "Enter a double and an intger: ";
    cin >> d >> i;
    print(d);
    print(i);
    return 0;
}

/*
Enter a double and an intger: 1.5 1
Generic: 1.5
Specific: 1
*/