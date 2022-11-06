#include <iostream>
using namespace std;

class Student
{
protected:
    int stu_id, stu_marks;
public:
    Student()
    {
        cout << "Enter ID and marks: ";
        cin>>stu_id>>stu_marks;
    }
    void show(int i)
    {
        cout << i<<". ID: "<<stu_id<<", Marks: "<<stu_marks<<endl;
    }
};

int main()
{
    int s;
    cout << "Enter total objects to create: ";
    cin>> s;
    Student *objs = new Student[s];
    for(int i=0; i<s; i++)objs[i].show(i);
    return 0;
}
