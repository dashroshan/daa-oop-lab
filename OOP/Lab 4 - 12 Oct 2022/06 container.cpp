#include <iostream>
using namespace std;

class Container
{
protected:
    double data;

public:
    Container(double data)
    {
        this->data = data;
    }
    virtual void volume() {}
};

class Sphere : public Container
{
public:
    Sphere(double radius) : Container(radius) {}
    void volume()
    {
        cout << "Volume of sphere: " << 4.0 / 3.0 * 3.141592 * data * data * data << endl;
    }
};

class Cube : public Container
{
public:
    Cube(double side) : Container(side) {}
    void volume()
    {
        cout << "Volume of cube: " << data * data * data << endl;
    }
};

int main()
{
    double radius, side;
    cout << "Enter radius of sphere and side of cube: ";
    cin >> radius >> side;
    Sphere s(radius);
    Cube c(side);
    s.volume();
    c.volume();
    return 0;
}

/*
Enter radius of sphere and side of cube: 4.5 5.5
Volume of sphere: 381.703
Volume of cube: 166.375
*/