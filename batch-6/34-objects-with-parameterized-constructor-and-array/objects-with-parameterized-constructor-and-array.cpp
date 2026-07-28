#include <iostream>
#include <vector>

using namespace std;

class clsA
{
public:

	int x;

	// parameterized constructor
	// initializes the object with a given value
	clsA(int value)
	{
		x = value;
	}

	void Print()
	{
		cout << "The value of x = " << x << endl;
	}
};

int main()
{
	// create an array of objects
	// each temporary object is intialized using the parameterized constructor
	clsA obj[] = { clsA(10), clsA(20), clsA(30) };

	// access each object in the array and print its value
	for (int i = 0; i < 3; i++)
	{
		obj[i].Print();
	}

	return 0;
}