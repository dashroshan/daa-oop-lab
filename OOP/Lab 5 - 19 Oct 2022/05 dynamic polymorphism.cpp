#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show()
    {
        cout << "Base::show() called\n";
    }
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "Derived::show() called\n";
    }
};

void display(Base &ref)
{
    ref.show();
}

int main()
{
    Base b;
    Derived d;
    display(b);
    display(d);
    return 0;
}

/*
Base::show() called
Derived::show() called
*/