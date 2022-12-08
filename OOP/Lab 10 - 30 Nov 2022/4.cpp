#include <iostream>
#include <fstream>
using namespace std;

class Book
{
public:
    char id[30], name[30];
    int yop;
};

int main()
{
    fstream fp;
    Book b;
    fp.open("Book_Details", ios::out | ios::binary);
    int total;
    cout << "Enter total books: ";
    cin >> total;
    for (int i = 0; i < total; i++)
    {
        cout << i + 1 << ". Enter book id, name, year: ";
        cin >> b.id >> b.name >> b.yop;
        fp.write((char *)&b, sizeof(Book));
    }
    fp.close();
    fp.open("Book_Details", ios::in | ios::binary);
    cout << "\nBooks ID, name, and year of publication:\n";
    while (fp.read((char *)&b, sizeof(Book)))
        cout << b.id << ", " << b.name << ", " << b.yop << endl;
    fp.close();
    return 0;
}