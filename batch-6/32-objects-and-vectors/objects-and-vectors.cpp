#include <iostream>
#include <vector>

using namespace std;

class clsA
{
public:

	int x;

	//Parametarized Constructor
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

	vector <clsA> v1;
	short NumberOfObjects = 5;

	clsA(10); // this is a temporary object, it will be destroyed immediately after this line, so it is not useful

	// inserting object at the end of vector
	for (int i = 0; i < NumberOfObjects; i++)
	{
		v1.push_back(clsA(i)); // this will create a temporary object and then copy it to the vector, so it is not efficient
	}

	// printing object content
	for (int i = 0; i < NumberOfObjects; i++)
	{
		v1[i].Print();

	}

	return 0;
}