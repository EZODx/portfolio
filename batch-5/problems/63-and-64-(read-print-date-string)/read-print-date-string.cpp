#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sDate
{
	short year;
	short month;
	short day;
};

string ReadStringDate(string message)
{
	string date;
	cout << message;
	getline(cin >> ws, date);

	return date;
}

vector <string> SplitString(string theString, string delime)
{


	vector <string> vString;

	string sWord;

	short pos = 0;

	while ((pos = theString.find(delime)) != std::string::npos)
	{

		sWord = theString.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		theString.erase(0, pos + delime.length());

	}

	if (theString != "")
	{
		vString.push_back(theString);
	}

	return vString;
}

sDate StringToDate(string stringDate)
{
	sDate date;
	vector <string> vDate;

	vDate = SplitString(stringDate, "/");

	date.day = stoi(vDate[0]);
	date.month = stoi(vDate[1]);
	date.year = stoi(vDate[2]);

	return date;
}

string DateToString(sDate date)
{
	return (to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year));
}

int main()
{

	string date = ReadStringDate("Please enter the date dd / mm / yyyy: ");

	sDate sDate = StringToDate(date);

	cout << "\nDay: " << sDate.day << endl;
	cout << "Month: " << sDate.month << endl;
	cout << "Year: " << sDate.year << endl;

	cout << "\nYou entered: " << DateToString(sDate) << endl;

	return 0;
}