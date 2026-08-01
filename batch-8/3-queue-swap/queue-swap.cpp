#include <iostream>
#include <queue>

using namespace std;

int main()
{

	queue <int> myQueue1;
	queue <int> myQueue2;

	myQueue1.push(10);
	myQueue1.push(20);
	myQueue1.push(30);
	myQueue1.push(40);

	myQueue2.push(50);
	myQueue2.push(60);
	myQueue2.push(70);
	myQueue2.push(80);

	myQueue1.swap(myQueue2);



	cout << "My Queue 1: ";
	while(!myQueue1.empty())
	{
		cout << myQueue1.front() << " ";

		myQueue1.pop();
	}

	cout << "\nMy Queue 2: ";
	while (!myQueue2.empty())
	{
		cout << myQueue2.front() << " ";

		myQueue2.pop();
	}

	return 0;
}