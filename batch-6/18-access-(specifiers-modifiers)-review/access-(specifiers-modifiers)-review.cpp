#include <iostream>

using namespace std;

class clsA
{
	// Access specifier: private, protected, public

private:
    int _var1;
    void _Fun1()
    {
        cout << "Function 1" << endl;
    }


protected:
    int var2 = 100;

    void Fun2()
    {
        cout << "Function 2" << endl;
    }


public:
    int var3;

    void Fun3()
    {
        cout << "Function 3" << endl;
    } 



};

class clsB : public clsA
{

public:

    void Func1()
    {
        cout << clsA::var2 << endl;
    }


};

int main()

{

    clsB objB;

    objB.Func1();

    return 0;
}