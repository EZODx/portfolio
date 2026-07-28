#include <iostream>
#include "clsPerson.h"
#include "clsEmployee.h"

using namespace std;

int main()
{

	clsPerson person1(10, "Mohammed", "Noah", "a@gmail.com", "8298982");
	person1.PrintInfo();

	cout << "\n\n\n";

	clsEmployee employee1(10, "Mohammed", "Noah", "a@gmail.com", "8298982", "CEO", "Engineering", 5000);
	employee1.PrintInfo();

	return 0;
}