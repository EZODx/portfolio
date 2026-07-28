#include <iostream>

using namespace std;

class clsPerson
{

public:

    string fullName = "Mohammed";

};

class clsEmployee : public clsPerson
{

public:
    string title = "CEO";

};

int main()

{
    clsEmployee employee1;
    cout << employee1.fullName << endl;

	/// Upcasting
    clsPerson* person1 = &employee1;
    cout << person1->fullName << endl;
    ////

	/// Downcasting
    clsPerson person2;
    clsEmployee* employee2 = &person2;
    ///

    return 0;
}