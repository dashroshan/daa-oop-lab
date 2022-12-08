#include <iostream>
using namespace std;

namespace myNs
{
    class employee
    {
    protected:
        int emp_id;
        double emp_salary;

    public:
        employee()
        {
            cout << "Enter employee id and salary: ";
            cin >> emp_id >> emp_salary;
        }
        void display()
        {
            cout << "EMPLOYEE DETAILS\nID: " << emp_id << "\nSalary: " << emp_salary;
        }
    };
    employee emp;
}

int main()
{
    using namespace myNs;
    emp.display();
    return 0;
}