#include <iostream>
#include <queue>

using namespace std;

int main()
{

	queue <int> myQueue;

	myQueue.push(10);
	myQueue.push(20);
	myQueue.push(30);
	myQueue.push(40);

	cout << "Count: " << myQueue.size();
	cout << "\nFront: " << myQueue.front();
	cout << "\nBack: " << myQueue.back();

	cout << "\n\nMy Queue: ";
	while(!myQueue.empty())
	{
		cout << myQueue.front() << " ";

		myQueue.pop();
	}

	return 0;
}