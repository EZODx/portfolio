#include <iostream>

using namespace std;

class clsPerson
{

public:

    virtual void Print()

    {
        cout << "Hi, I'm a Person!\n";
    }

};

class clsEmployee : public clsPerson
{
public:
    void Print()
    {
        cout << "Hi, I'm an Employee\n";
    }
};

class clsStudent : public clsPerson
{
public:
    void Print()
    {
        cout << "Hi, I'm a Student\n";
    }
};


int main()

{

    clsEmployee Employee1;
    clsStudent  Student1;

    Employee1.Print();
    Student1.Print();


    cout << "\n\n";

    clsPerson* Person1 = &Employee1;
    clsPerson* Person2 = &Student1;

    Person1->Print();
    Person2->Print();

    return 0;
}