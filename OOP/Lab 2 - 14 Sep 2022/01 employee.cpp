// WAP to create a class named as Employee with private attributes empID and
// empSalary. Provide appropriate public interfaces to initialise these
// attributes to display the details.

#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    void get()
    {
        cout << "Enter employee ID, and salary: ";
        cin >> id >> salary;
    }
    void display()
    {
        cout << "\nEMPLOYEE DETAILS\nID: " << id << "\nSalary: " << salary << "\n";
    }
};

int main()
{
    Employee emp;
    emp.get();
    emp.display();
    return (0);
}

/*
Enter employee ID, and salary: 12345 86000.5

EMPLOYEE DETAILS
ID: 12345
Salary: 86000.5
*/