// Check if a given character is a vowel or a consonant

#include <iostream>
using namespace std;

int main()
{
    char c;
    cout << "Enter character: ";
    cin >> c;
    if (!isalpha(c))
        cout << "Neither a vowel, nor a consonant";
    c = tolower(c);
    for (char v : "aeiou")
        if (c == v)
        {
            cout << "It is a vowel";
            return 0;
        }
    cout << "It is a consonant";
    return 0;
}

/*
Enter character: o
It is a vowel
*/