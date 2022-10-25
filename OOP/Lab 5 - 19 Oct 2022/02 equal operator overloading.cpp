#include <iostream>
using namespace std;

class Var
{
protected:
    int x, y;

public:
    Var(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    bool operator==(Var v)
    {
        return (x == v.x && y == v.y);
    }
};

int main()
{
    int x, y;
    cout << "Enter x and y for object a: ";
    cin >> x >> y;
    Var a(x, y);
    cout << "Enter x and y for object b: ";
    cin >> x >> y;
    Var b(x, y);

    if (a == b)
        cout << "Both objects are equal";
    else
        cout << "Both objects are unequal";
    return 0;
}

/*
Enter x and y for object a: 2 2
Enter x and y for object b: 2 2
Both objects are equal
*/