#include <iostream>
using namespace std;

class NoInheritance
{
private:
    NoInheritance() {}
};

class Derived : public NoInheritance
{
    // Result in compile time error
};

int main()
{
    Derived d;
    return 0;
}

/*
error: 'NoInheritance::NoInheritance()' is private within this context
*/