#include <iostream>

using namespace std;

enum enMonthOfYear {Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5,
			        Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10,
				    Nov = 11, Dec = 12};

int ReadNumberInRange(string Message, int From, int To)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	}
	while (Number < From || Number > To);

	return Number;
}

enMonthOfYear ReadMonthOfYear()
{
	return (enMonthOfYear)ReadNumberInRange("Please enter the number of Month (1 Jan - 12 Dec) : ", 1, 12);
}

string GetmMonthOfYear(enMonthOfYear Month)
{
	switch (Month)
	{
	case enMonthOfYear::Jan:
		return "It's January";
	case enMonthOfYear::Feb:
		return "It's Febuary";
	case enMonthOfYear::Mar:
		return "It's March";
	case enMonthOfYear::Apr:
		return "It's April";
	case enMonthOfYear::May:
		return "It's May";
	case enMonthOfYear::Jun:
		return "It's June";
	case enMonthOfYear::Jul:
		return "It's July";
	case enMonthOfYear::Aug:
		return "It's August";
	case enMonthOfYear::Sep:
		return "It's September";
	case enMonthOfYear::Oct:
		return "It's October";
	case enMonthOfYear::Nov:
		return "It's November";
	case enMonthOfYear::Dec:
		return "It's December";
	default:
		return "Not a valid Number!!";
	}
}

int main()
{

	cout << endl << GetmMonthOfYear(ReadMonthOfYear()) << endl;

	return 0;
}