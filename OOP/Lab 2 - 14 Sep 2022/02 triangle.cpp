// WAP to create a class named as Triangle with 3 sides as its attributes. The
// attributes need to be placed under protected visibility. Provide another
// function to initialise these attributes and a method which finds out the area
// or triangle object and display the value of area at the console.

#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
private:
    double a, b, c;

public:
    void get()
    {
        cout << "Enter sides: ";
        cin >> a >> b >> c;
    }
    double area()
    {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main()
{
    Triangle t;
    t.get();
    cout << "Area of the triangle: " << t.area();
    return (0);
}

/*
Enter sides: 3 4 5
Area of the triangle: 6
*/