#include <iostream>
using namespace std;

class Ambiguity
{
private:
    int a, b;

public:
    Ambiguity(int a, int b = 5)
    {
        this->a = a;
        this->b = b;
    }

    Ambiguity(int a)
    {
        this->a = a;
        this->b = 10;
    }
};

int main()
{
    // This doesnot work, as it is ambiguious for the compiler to find what
    // constructor to use as both the overloaded constructors are matched
    Ambiguity a(1);
    return 0;
}