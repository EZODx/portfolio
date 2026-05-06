#include <iostream>

using namespace std;

enum enOperationType {Add = '+', Subtract = '-',
					Muliply = '*', Divide = '/' };

float ReadNumber(string Message)
{
	float Number;
	cout << Message << endl;
	cin >> Number;

	return Number;
}

enOperationType ReadOperationType()
{
	char OT;
	cout << "Please enter operation type ( + , - , * , / ) : " << endl;
	cin >> OT;

	return (enOperationType)OT;
}

float Calculate(float Number1, float Number2, enOperationType OT)
{
	switch (OT)
	{
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Subtract:
		return Number1 - Number2;
	case enOperationType::Muliply:
		return Number1 * Number2;
	case enOperationType::Divide:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

int main()
{
	float Number1 = ReadNumber("Please enter number 1 : ");
	float Number2 = ReadNumber("Please enter number 2 : ");

	enOperationType OpType = ReadOperationType();

	cout << "Result : " << Calculate(Number1, Number2, OpType) << endl;

	return 0;
}