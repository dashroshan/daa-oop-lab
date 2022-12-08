#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string s;
    fstream invoiceFile;
    invoiceFile.open("invoice.txt", ios::out);
    string name, code;
    double price;
    int total;
    cout << "Enter total item: ";
    cin >> total;
    for (int i = 0; i < total; i++)
    {
        cout << i + 1 << ". Enter item name, code, and price: ";
        cin >> name >> code >> price;
        invoiceFile << name << ", " << code << ", " << price << endl;
    }
    invoiceFile.close();
    cout << "\n Items name,code,and prices:\n";
    invoiceFile.open("invoice.txt", ios::in);
    while (getline(invoiceFile, s))
        cout << s << endl;
    invoiceFile.close();
    return 0;
}