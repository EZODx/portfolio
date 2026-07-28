#include <iostream>
using namespace std;

class clsA
{
public:
    int x;

    // default constructor (used when creating array with new[])
    clsA() {}

    // parameterized constructor
    clsA(int value)
    {
        x = value;
    }

    void Print()
    {
        cout << "x = " << x << endl;
    }
};

int main()
{
    short numberOfObjects = 5;

    // allocate array of objects in dynamic memory(heap),
    // calls default constructor for each element
    clsA* arrA = new clsA[numberOfObjects];

    // assign values using temporary objects, then copy assigned to array elements
    for (int i = 0; i < numberOfObjects; i++)
    {
        arrA[i] = clsA(i);
    }

    // print values of array
    for (int i = 0; i < numberOfObjects; i++)
    {
        arrA[i].Print();
    }

    // free memory
    delete[] arrA;

    return 0;
}