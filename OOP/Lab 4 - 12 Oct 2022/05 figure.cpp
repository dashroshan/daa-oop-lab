#include <iostream>
using namespace std;

class Figure
{
protected:
    double data;

public:
    Figure(double data)
    {
        this->data = data;
    }
    virtual void show_area() {}
};

class Circle : public Figure
{
public:
    Circle(double radius) : Figure(radius) {}
    void show_area()
    {
        cout << "Area of circle: " << 2 * 3.141592 * data << endl;
    }
};

class Square : public Figure
{
public:
    Square(double side) : Figure(side) {}
    void show_area()
    {
        cout << "Area of square: " << data * data << endl;
    }
};

int main()
{
    double radius, side;
    cout << "Enter radius of circle and side of square: ";
    cin >> radius >> side;
    Circle c(radius);
    Square s(side);
    c.show_area();
    s.show_area();
    return 0;
}

/*
Enter radius of circle and side of square: 4.5 3.2
Area of circle: 28.2743
Area of square: 10.24
*/