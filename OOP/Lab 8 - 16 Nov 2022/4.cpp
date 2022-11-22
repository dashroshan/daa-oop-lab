#include <bits/stdc++.h>
using namespace std;

template <typename t>
class Stack
{
private:
    t *data;
    int top;
    int size;

public:
    Stack(int n)
    {
        data = new int[n];
        size = n;
        top = -1;
    }
    void push()
    {
        if (top > size - 2)
        {
            cout << "Stack overflow!\n";
            return;
        }
        t n;
        cout << "Enter element: ";
        cin >> n;
        data[++top] = n;
        cout << n << " pushed to stack!\n";
    }
    void pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow!\n";
            return;
        }
        cout << data[top--] << " popped from stack!\n";
    }
    void display()
    {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter size of stack: ";
    cin >> n;
    Stack<int> s(n);
loop:
    cout << "\n1. Push\n2. Pop\n3. Display\n\nEnter choice: ";
    cin >> n;
    switch (n)
    {
    case 1:
        s.push();
        goto loop;
    case 2:
        s.pop();
        goto loop;
    case 3:
        s.display();
        goto loop;
    }
    return 0;
}

/*
Enter size of stack: 5

1. Push
2. Pop
3. Display

Enter choice: 1
Enter element: 5
5 pushed to stack!

1. Push
2. Pop
3. Display

Enter choice: 1
Enter element: 6
6 pushed to stack!

1. Push
2. Pop
3. Display

Enter choice: 3
Stack: 6 5

1. Push
2. Pop
3. Display

Enter choice: 2
6 popped from stack!

1. Push
2. Pop
3. Display

Enter choice: 3
Stack: 5

1. Push
2. Pop
3. Display

Enter choice:
*/