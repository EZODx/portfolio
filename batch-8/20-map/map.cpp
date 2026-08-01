#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int> studentGrades;

	studentGrades["Mohammed"] = 40;
	studentGrades["Jack"] = 80;

	cout << "All map values:\n\n";
	for (const auto& pair : studentGrades)
	{
		cout << "Student Name: " << pair.first << ", Grade: " << pair.second << endl;
	}

	cout << "\nFinding Mohammed's Grade in the map:\n";
	string studentName = "Mohammed";
	if (studentGrades.find(studentName) != studentGrades.end())
	{
		cout << "Student Name: " << studentName << ", Grade: " << studentGrades[studentName] << endl;
	}
	else
	{
		cout << "Grade not found for " << studentName << endl;
	}

	cout << "\nFinding Zirak's Grade in the map:\n";
	studentName = "Zirak";
	if (studentGrades.find(studentName) != studentGrades.end())
	{
		cout << "Student Name: " << studentName << ", Grade: " << studentGrades[studentName] << endl;
	}
	else
	{
		cout << "Grade not found for " << studentName << endl;
	}

	return 0;
}