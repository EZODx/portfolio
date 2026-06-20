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

string ReplaceWordsInString(string str, string stringToReplace, string replaceTo)
{

	short pos = str.find(stringToReplace);

	while (pos != std::string::npos)
	{

		str = str.replace(pos, stringToReplace.length(), replaceTo);
		pos = str.find(stringToReplace);

	}


	return str;
}

string FormatDate(sDate date, string format = "dd/mm/yyyy")
{
	string formattedDateString = "";

	formattedDateString = ReplaceWordsInString(format, "dd", to_string(date.day));
	formattedDateString = ReplaceWordsInString(formattedDateString, "mm", to_string(date.month));
	formattedDateString = ReplaceWordsInString(formattedDateString, "yyyy", to_string(date.year));

	return formattedDateString;
}

int main()
{

	string date = ReadStringDate("Please enter the date dd/mm/yyyy: ");

	sDate sDate = StringToDate(date);

	cout << "\n" << FormatDate(sDate, "yyyy/dd/mm") << endl;

	cout << "\n" << FormatDate(sDate, "mm/dd/yyyy") << endl;

	cout << "\n" << FormatDate(sDate, "mm-dd-yyyy") << endl;

	cout << "\n" << FormatDate(sDate, "dd-mm-yyyy") << endl;

	cout << "\n" << FormatDate(sDate, "Day: dd, Month: mm, Year: yyyy") << endl;



	return 0;
}