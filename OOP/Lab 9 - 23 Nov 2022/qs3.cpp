#include <iostream>
using namespace std;

namespace outer
{
    string so = "Inside outer!\n";
    namespace inner
    {
        string si = "Inside outer::inner!";
    }
}

int main()
{
    cout << outer::so;
    cout << outer::inner::si;
    return 0;
}