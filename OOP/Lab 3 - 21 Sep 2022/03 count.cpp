#include <iostream>
using namespace std;

class CountObj
{
public:
    CountObj()
    {
        static int count;
        count++;
        cout << "Object created! Current total: " << count << "\n";
    }
};

int main()
{
    CountObj o1, o2, o3;
    return 0;
}