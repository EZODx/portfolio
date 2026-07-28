#include <iostream>

using namespace std;

class clsA
{

public:

    static int func1()
    {
        return 10;
    }

    int func2()
    {
        return 20;
    }


};

int main()
{

    clsA A1, A2;

    cout << clsA::func1() << endl;
	//cout << clsA::func2() << endl; // error: 'func2' is not a static member of 'clsA'

    cout << A1.func1() << endl; // not recommended but it works
    cout << A2.func1() << endl; // not recommended but it works

    cout << "\n";
    cout << A1.func2() << endl;

    return 0;
}