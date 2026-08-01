#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack <int> myStack1;
	stack <int> myStack2;

	myStack1.push(10);
	myStack1.push(20);
	myStack1.push(30);
	myStack1.push(40);

	myStack2.push(50);
	myStack2.push(60);
	myStack2.push(70);
	myStack2.push(80);

	myStack1.swap(myStack2);

	cout << "Stack 1: ";
	while (!myStack1.empty())
	{
		cout << myStack1.top() << " ";
		myStack1.pop();
	}

	cout << "\nStack 2: ";
	while (!myStack2.empty())
	{
		cout << myStack2.top() << " ";
		myStack2.pop();
	}


}