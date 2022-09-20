// WAP to create a class named as convert which contains private attributes
// named as seconds. Provide a public interface that would accept the positive
// integer values from user and initialise seconds. Provide another public
// interface that would convert seconds value to hours, minutes, and seconds and
// display as hours : minutes : seconds

#include <iostream>
using namespace std;

class Convert
{
private:
    int sec;

public:
    void get()
    {
        cout << "Enter seconds: ";
        cin >> sec;
    }
    void display()
    {
        int s = sec % 60;
        int m = (sec / 60) % 60;
        int h = (sec / 3600) % 60;
        cout << h << " : " << m << " : " << s;
    }
};

int main()
{
    Convert c;
    c.get();
    c.display();
    return (0);
}

/*
Enter seconds: 5000
1 : 23 : 20
*/