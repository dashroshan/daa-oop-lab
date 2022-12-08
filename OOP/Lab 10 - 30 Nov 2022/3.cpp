#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fp;
    string s;
    fp.open("Mytext.txt", ios::in);
    int chars = 0, words = 0, lines = 0;
    while (getline(fp, s))
    {
        lines++;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == ' ')
                words++;
            else if (ch != '\n')
                chars++;
        }
    }
    words += lines;
    fp.close();
    cout << "Total chars=" << chars << ", words=" << words << ", lines=" << lines;
    return 0;
}