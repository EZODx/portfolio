#include <iostream>

using namespace std;

class clsAddress
{
private:
    string _fullName;

public:

	// Constructor
    clsAddress()
    {
        _fullName = "Zirak Mohammed";
        cout << "Hi, I'm the constructor" << endl;
    }

	// Destructor
    ~clsAddress()
    {
        _fullName = "Zirak Mohammed";
        cout << "Hi, I'm the destructor" << endl;
    }

};

void Func1()
{
    clsAddress address1;

}

void Func2()
{
	clsAddress* address2 = new clsAddress; // Dynamic allocation of an object
	delete address2; // Deallocate memory to call the destructor
}

int main()
{
    
    Func1();
    Func2();

    return 0;
}