#include <iostream>
using namespace std;

class Var
{
protected:
    double x, y;

public:
    Var() {}
    Var(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Var operator+(Var v)
    {
        return Var(x + v.x, y + v.y);
    }
    Var operator-(Var v)
    {
        return Var(x - v.x, y - v.y);
    }
    Var operator*(Var v)
    {
        return Var(x * v.x, y * v.y);
    }
    Var operator/(Var v)
    {
        return Var(x / v.x, y / v.y);
    }
    void display(string text)
    {
        cout << text << ": x=" << x << ", y=" << y << endl;
    }
};

int main()
{
    double x, y;
    cout << "Enter x and y for object a: ";
    cin >> x >> y;
    Var a(x, y);
    cout << "Enter x and y for object b: ";
    cin >> x >> y;
    Var b(x, y), c;

    c = a + b;
    c.display("a + b");
    c = a - b;
    c.display("a - b");
    c = a * b;
    c.display("a * b");
    c = a / b;
    c.display("a / b");

    return 0;
}

/*
Enter x and y for object a: 2 3
Enter x and y for object b: 8 1
a + b: x=10, y=4
a - b: x=-6, y=2
a * b: x=16, y=3
a / b: x=0.25, y=3
*/