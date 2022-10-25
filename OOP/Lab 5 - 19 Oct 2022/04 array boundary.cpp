#include <iostream>
using namespace std;

class Arr
{
protected:
    int *nums, size;

public:
    Arr(int s)
    {
        nums = new int[s];
        size = s;
        cout << "Enter array elements: ";
        for (int i = 0; i < s; i++)
            cin >> nums[i];
    }
    int operator[](int i)
    {
        if (i < 0 || i >= size)
            return NULL;
        else
            return nums[i];
    }
};

int main()
{
    int s, i, e;
    cout << "Enter array size: ";
    cin >> s;
    Arr a(s);
    cout << "Enter index to access: ";
    cin >> i;
    cout << "Array[" << i << "] = " << ((a[i] == NULL) ? "Undefined" : to_string(a[i]));
    return 0;
}

/*
Enter array size: 3
Enter array elements: 1 2 3
Enter index to access: 5
Array[5] = Undefined
*/