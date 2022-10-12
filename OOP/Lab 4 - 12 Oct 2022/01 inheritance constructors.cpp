#include <iostream>
using namespace std;

class Base1
{
protected:
    int n1;

public:
    Base1(int n1)
    {
        this->n1 = n1;
    }
};

class Base2
{
protected:
    int n2, n3, n4;

public:
    Base2(int n2, int n3, int n4)
    {
        this->n2 = n2;
        this->n3 = n3;
        this->n4 = n4;
    }
};

class Derived : public Base1, public Base2
{
public:
    Derived(int n1, int n2, int n3, int n4) : Base1(n1), Base2(n2, n3, n4) {}
    void show()
    {
        cout << "Data in members from Base1: " << n1 << endl
             << "Data in members from Base2: " << n2 << " " << n3 << " " << n4;
    }
};

int main()
{
    int n1, n2, n3, n4;
    cout << "Enter 4 integer data: ";
    cin >> n1 >> n2 >> n3 >> n4;
    Derived d(n1, n2, n3, n4);
    d.show();
    return 0;
}

/*
Enter 4 integer data: 1 2 3 4
Data in members from Base1: 1
Data in members from Base2: 2 3 4
*/