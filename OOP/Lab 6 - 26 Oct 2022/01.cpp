#include <iostream>
using namespace std;

int main()
{
    int s;
    cout << "Enter array size: ";
    cin>>s;
    double *a=new double[s];
    cout << "Enter array elements: ";
    for(int i=0; i<s; i++) cin>>a[i];
    cout << "Array created!\n\nArray: ";
    for(int i=0; i<s; i++) cout << a[i]<<" ";
    delete []a;
    cout << "\nArray deleted!";
    return 0;
}
