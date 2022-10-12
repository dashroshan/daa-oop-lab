#include <iostream>
using namespace std;

class Staff
{
protected:
    int id;
    long long int phone;

public:
    Staff(int id, long long int phone)
    {
        this->id = id;
        this->phone = phone;
    }
    void display()
    {
        cout << "STAFF DETAILS" << endl
             << "ID: " << id << endl
             << "Phone: " << phone << endl
             << endl;
    }
};

class Officer : public Staff
{
protected:
    int grade;

public:
    Officer(int id, long long int phone, int grade) : Staff(id, phone)
    {
        this->grade = grade;
    }
    void display()
    {
        cout << "OFFICER STAFF DETAILS" << endl
             << "ID: " << id << endl
             << "Phone: " << phone << endl
             << "Grade: " << grade << endl
             << endl;
    }
};

class Teacher : public Staff
{
protected:
    int years_of_experience;

public:
    Teacher(int id, long long int phone, int years_of_experience) : Staff(id, phone)
    {
        this->years_of_experience = years_of_experience;
    }
    void display()
    {
        cout << "TEACHER STAFF DETAILS" << endl
             << "ID: " << id << endl
             << "Phone: " << phone << endl
             << "Years of experience: " << years_of_experience << endl
             << endl;
    }
};

class Regular : public Teacher
{
protected:
    double basic_pay, da, hra, gross;

public:
    Regular(int id, long long int phone, int years_of_experience, double basic_pay) : Teacher(id, phone, years_of_experience)
    {
        this->basic_pay = basic_pay;
        this->hra = 0.2 * basic_pay;
        this->da = 1.5 * basic_pay;
        this->gross = basic_pay + da + hra;
    }
    void display()
    {
        cout << "REGULAR TEACHER STAFF DETAILS" << endl
             << "ID: " << id << endl
             << "Phone: " << phone << endl
             << "Years of experience: " << years_of_experience << endl
             << "Basic pay: " << basic_pay << endl
             << "DA: " << da << endl
             << "HRA: " << hra << endl
             << "Gross: " << gross << endl
             << endl;
    }
};

class Contract : public Teacher
{
protected:
    double pay_consolidated, contract_duration_months;

public:
    Contract(int id, long long int phone, int years_of_experience, double pay_consolidated, double contract_duration_months) : Teacher(id, phone, years_of_experience)
    {
        this->pay_consolidated = pay_consolidated;
        this->contract_duration_months = contract_duration_months;
    }
    void display()
    {
        cout << "CONTRACT TEACHER STAFF DETAILS" << endl
             << "ID: " << id << endl
             << "Phone: " << phone << endl
             << "Years of experience: " << years_of_experience << endl
             << "Pay consolidated: " << pay_consolidated << endl
             << "Contract duration in months: " << contract_duration_months << endl
             << endl;
    }
};

int main()
{
    int id, years_of_experience, grade;
    long long int phone;
    double basic_pay, pay_consolidated, contract_duration_months;

    cout << "Enter staff id, phone: ";
    cin >> id >> phone;
    Staff s(id, phone);
    s.display();

    cout << "Enter officer staff id, phone, grade: ";
    cin >> id >> phone >> grade;
    Officer o(id, phone, grade);
    o.display();

    cout << "Enter teacher staff id, phone, years of experience: ";
    cin >> id >> phone >> years_of_experience;
    Teacher t(id, phone, years_of_experience);
    t.display();

    cout << "Enter regular teacher staff id, phone, years of experience, basic pay: ";
    cin >> id >> phone >> years_of_experience >> basic_pay;
    Regular r(id, phone, years_of_experience, basic_pay);
    r.display();

    cout << "Enter contract teacher staff id, phone, years of experience, pay consolidated, contract duration in months: ";
    cin >> id >> phone >> years_of_experience >> pay_consolidated >> contract_duration_months;
    Contract c(id, phone, years_of_experience, pay_consolidated, contract_duration_months);
    c.display();
    return 0;
}

/*
Enter staff id, phone: 12341 1234567891
STAFF DETAILS
ID: 12341
Phone: 1234567891

Enter officer staff id, phone, grade: 12342 1234567892 2
OFFICER STAFF DETAILS
ID: 12342
Phone: 1234567892
Grade: 2

Enter teacher staff id, phone, years of experience: 12343 1234567893 3
TEACHER STAFF DETAILS
ID: 12343
Phone: 1234567893
Years of experience: 3

Enter regular teacher staff id, phone, years of experience, basic pay: 12344 1234567894 4 45000.5
REGULAR TEACHER STAFF DETAILS
ID: 12344
Phone: 1234567894
Years of experience: 4
Basic pay: 45000
DA: 67500
HRA: 9000
Gross: 121500

Enter contract teacher staff id, phone, years of experience, pay consolidated, contract duration in months: 12345 1234567895 5 55000 15
CONTRACT TEACHER STAFF DETAILS
ID: 12345
Phone: 1234567895
Years of experience: 5
Pay consolidated: 55000
Contract duration in months: 15
*/