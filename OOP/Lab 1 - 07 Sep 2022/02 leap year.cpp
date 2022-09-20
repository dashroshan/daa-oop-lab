// Check if a given year is a leap year or not

#include <iostream>
using namespace std;

int main()
{
    int y;
    cout << "Enter year: ";
    cin >> y;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        cout << "It is a leap year";
    else
        cout << "It is not a leap year";
    return 0;
}

/*
Enter year: 2020
It is a leap year
*/