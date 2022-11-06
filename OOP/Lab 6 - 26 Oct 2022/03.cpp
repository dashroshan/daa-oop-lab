#include <iostream>
using namespace std;

class Var
{
protected:
    int *x;

public:
    Var(int xVal)
    {
        x = new int;
        *x = xVal;
    }
    Var(Var &v)
    {
        x = new int(*v.x);
    }
    void clear()
    {
        delete x;
    }
    void show()
    {
        cout << "x: " << *x << endl;
    }
};

int main()
{
    Var v1(5);
    Var v2 = v1;
    v1.clear();
    v2.show();
    return 0;
}
