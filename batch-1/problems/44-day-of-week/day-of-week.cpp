#include <iostream>

using namespace std;

enum enDayOfWeek { Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7 };

int ReadNumberInRange(string Message, int From, int To)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < From || Number > To);

	return Number;
}

enDayOfWeek ReadDayOfWeek()
{
	return (enDayOfWeek)ReadNumberInRange("Please enter the number of day (1 Sun - 7 Sat) : ", 1, 7);
}

string GetDayOfWeek(enDayOfWeek Day)
{
	switch (Day)
	{
	case enDayOfWeek::Sun:
		return "It's Sunday";
	case enDayOfWeek::Mon:
		return "It's Monday";
	case enDayOfWeek::Wed:
		return "It's Wednesday";
	case enDayOfWeek::Thu:
		return "It's Thursday";
	case enDayOfWeek::Fri:
		return "It's Friday";
	case enDayOfWeek::Sat:
		return "It's Saturday";
	default:
		return "Not a valid Number!!";
	}
}

int main()
{

	cout << endl << GetDayOfWeek(ReadDayOfWeek()) << endl;


	return 0;
}