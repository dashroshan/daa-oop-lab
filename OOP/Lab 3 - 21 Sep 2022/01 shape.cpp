#include <iostream>
using namespace std;

class Shape
{
private:
    double x, y;

public:
    void set(double x)
    {
        this->x = x;
        this->y = x;
        cout << "Treating input as square...\n";
    }

    void set(double x, double y)
    {
        this->x = x;
        this->y = y;
        cout << "Treating input as rectangle...\n";
    }

    double area()
    {
        return x * y;
    }
};

int main()
{
    double x, y;
    char c;
    Shape s;
    cout << "Enter side of square or length and breadth of rectangle: ";
    scanf("%lf%c", &x, &c);
    if (c == ' ')
    {
        cin >> y;
        s.set(x, y);
    }
    else
        s.set(x);
    cout << "Area: " << s.area();
    return 0;
}