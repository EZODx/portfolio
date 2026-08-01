#include <iostream>

using namespace std;

union myUnion
{
	int intValue;
	float floatValue;
	char charValue;
};

int main()
{
	myUnion union1;

	union1.intValue = 10;
	cout << "int value: " << union1.intValue << endl;

	union1.floatValue = 3.14;
	cout << "float value: " << union1.floatValue << endl;

	union1.charValue = 'E';
	cout << "char value: " << union1.charValue << endl;

	return 0;
}