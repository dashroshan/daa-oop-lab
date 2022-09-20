// WAP to create a class named as Customers which would store the details about
// bank customers. The private attributes of the class are accountNumber,
// balanceAmount, and panNumber. Provide appropriate public interfaces to
// initialise these attributes and display at the console. Atleast 25 different
// customer details need to be diaplayed.

#include <iostream>
using namespace std;

class Customer
{
private:
    int accountNumber;
    double balanceAmount;
    int panNumber;

public:
    void get()
    {
        cout << "Enter account number, balance amount, and pan number: ";
        cin >> accountNumber >> balanceAmount >> panNumber;
    }
    void display()
    {
        cout << "\nCUSTOMER DETAILS\nAccount Number: " << accountNumber << "\nBalance Amount: " << balanceAmount << "\nPAN Number: " << panNumber << "\n";
    }
};

int main()
{
    const int t = 2;
    Customer cust[t];
    for (int i = 0; i < t; i++)
        cust[i].get();
    for (int i = 0; i < t; i++)
        cust[i].display();
    return (0);
}

/*
Enter account number, balance amount, and pan number: 12341 50001 1234561
Enter account number, balance amount, and pan number: 12342 50002 1234562

CUSTOMER DETAILS
Account Number: 12341
Balance Amount: 50001
PAN Number: 1234561

CUSTOMER DETAILS
Account Number: 12342
Balance Amount: 50002
PAN Number: 1234562
*/