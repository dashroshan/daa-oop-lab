#include <iostream>
#include <fstream>
using namespace std;
fstream fp;
char ch;

void display()
{
    cout << "File conent: ";
    fp.open("data", ios::in | ios::binary);
    while (fp.read(&ch, sizeof(ch)))
        cout << ch;
    fp.close();
    cout << endl;
}

void saveReplace(string text)
{
    fp.open("data", ios::out | ios::binary);
    fp.write(text.c_str(), text.size());
    fp.close();
    display();

    fp.open("data", ios::out | ios::in | ios::binary);
    fp.seekp(19);
    cout << "Enter new 20th character: ";
    cin >> ch;
    fp.write(&ch, sizeof(ch));
    fp.close();

    display();
}

int main()
{
    cout << "Enter text: ";
    string text;
    cin >> text;
    cout << endl;
    saveReplace(text);
    return 0;
}

/*
Enter text: oooooooooooooooooooooooooooooo

File conent: oooooooooooooooooooooooooooooo
Enter new 20th character: R
File conent: oooooooooooooooooooRoooooooooo
*/