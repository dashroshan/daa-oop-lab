#include <iostream>
using namespace std;

class Var
{
protected:
    int x;

public:
    Var() {}
    Var(int x)
    {
        this->x = x;
    }
    friend int operator-(Var v, int n)
    {
        return (v.x - n);
    }
    friend int operator-(int n, Var v)
    {
        return (n - v.x);
    }
};

int main()
{
    int x;
    cout << "Enter number for obj: ";
    cin >> x;
    Var v(x);
    cout << "Enter number for int: ";
    cin >> x;

    cout << "Obj - Int = " << v - x << endl
         << "Int - Obj = " << x - v;
    return 0;
}

/*
Enter number for obj: 3
Enter number for int: 2
Obj - Int = 1
Int - Obj = -1
*/