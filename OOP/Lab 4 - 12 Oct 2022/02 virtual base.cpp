#include <iostream>
using namespace std;

class GrandParent
{
public:
    int data;
};

class Parent1 : public virtual GrandParent
{
};
class Parent2 : public virtual GrandParent
{
};

class Child : public Parent1, public Parent2
{
};

int main()
{
    Child c;
    cout << "Enter an integer data: ";
    cin >> c.data;
    cout << "Data: " << c.data;
    return 0;
}

/*
Enter an integer data: 3
Data: 3
*/