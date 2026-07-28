#include <iostream>

using namespace std;

class clsA
{

public:


    static int counter;
    int var = 0;

    clsA()
    {
        counter++;
    }

    void Print()
    {
        cout << "var     = " << var << endl;
        cout << "counter = " << counter << "\n\n";

    }

};

int clsA::counter = 0; // Initialize the static member variable

int main()
{
    clsA A1, A2, A3;

    A1.var = 10;
    A2.var = 20;
    A3.var = 30;

    A1.Print();
    A2.Print();
    A3.Print();

    A2.counter = 50;

	cout << "After changing the static member counter in one object:\n\n";

    A1.Print();
    A2.Print();
    A3.Print();

    return 0;
}