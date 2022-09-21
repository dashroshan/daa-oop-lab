#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
protected:
    double x, y, z;

public:
    Triangle(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    bool check(double x, double y, double z)
    {
        return (abs(x * x - y * y - z * z) < 0.001);
    }

    double area(double b, double h)
    {
        cout << "Using right-angle triangle formula for area...\n";
        return 0.5 * b * h;
    }

    double area()
    {
        cout << "Using heron's formula for area...\n";
        double s = (x + y + z) / 2.0;
        return sqrt(s * (s - x) * (s - y) * (s - z));
    }

    void display()
    {
        double a;
        if (check(x, y, z))
            a = area(y, z);
        else if (check(y, z, x))
            a = area(z, x);
        else if (check(z, x, y))
            a = area(x, y);
        else
            a = area();
        cout << "Area: " << a;
    }
};

int main()
{
    double x, y, z;
    cout << "Enter sides of triangle: ";
    cin >> x >> y >> z;
    Triangle t(x, y, z);
    t.display();
    return 0;
}