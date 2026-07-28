#include <iostream>

using namespace std;

class clsPerson
{

private:

    string _firstName;

public:


    void SetFirstName(string firstName) {

        _firstName = firstName;

    }

    string GetFirstName() {

        return _firstName;

    }

    __declspec(property(get = GetFirstName, put = SetFirstName)) string firstName;

};

int main()

{

    clsPerson person1;

    person1.SetFirstName("EZOD");
    cout << person1.GetFirstName() << endl;

    //instead of the above we only write this
    person1.firstName = "EZOD";
    cout << person1.firstName;

    return 0;
}
