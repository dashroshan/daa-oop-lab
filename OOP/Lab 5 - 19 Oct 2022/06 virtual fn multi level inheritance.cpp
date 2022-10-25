#include <iostream>
using namespace std;

class GrandParent
{
public:
    virtual void show() = 0;
};

class Parent : public GrandParent
{
public:
    virtual void show() = 0;
};

class Child : public Parent
{
public:
    void show()
    {
        cout << "Child::show() called using GrandParent pointer\n";
    }
};

int main()
{
    GrandParent *ptr;
    Child obj;
    ptr = &obj;
    ptr->show();
    return 0;
}

/*
Child::show() called using GrandParent pointer
*/