#include <iostream>
using namespace std;

class A
{
protected:
    char c;
    int i;

public:
    A(char cc, int ii)
    {
        c = cc;
        i = ii;
    }

    void display() const
    {
        cout << "Character: " << c << "\nInteger: " << i;
    }
};

int main()
{
    char c;
    int i;
    cout << "Enter a character and integer: ";
    cin >> c >> i;
    A const obj(c, i);
    obj.display();
    return 0;
}