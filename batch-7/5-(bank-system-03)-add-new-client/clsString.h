#pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString
{

private:
	string _value;

public:

	clsString()
	{
		_value = "";
	}

	clsString(string value)
	{
		_value = value;
	}

	void SetValue(string value)
	{
		_value = value;
	}

	string GetValue()
	{
		return _value;
	}

	//////////////////////////////////////////////////////

	static short Length(string theString)
	{
		return theString.length();
	}

	short Length()
	{
		return _value.length();
	}
	/////////

	static short CountWords(string theString)
	{

		string delime = " ";

		short counter = 0;
		string sWord;
		short pos = 0;

		while ((pos = theString.find(delime)) != std::string::npos)
		{

			sWord = theString.substr(0, pos);

			if (sWord != "")
			{
				counter++;
			}

			theString.erase(0, pos + delime.length());

		}

		if (theString != "")
		{
			counter++;
		}

		return counter;
	}

	short CountWords()
	{
		return CountWords(_value);
	}
	/////////

	static string UpperFirstLetterOfEachWord(string theString)
	{

		bool isFirstLetter = true;

		for (int i = 0; i < theString.length(); i++)
		{
			if (theString[i] != ' ' && isFirstLetter)
			{
				theString[i] = toupper(theString[i]);
			}

			isFirstLetter = (theString[i] == ' ' ? true : false);
		}

		return theString;
	}

	void UpperFirstLetterOfEachWord()
	{
		_value = UpperFirstLetterOfEachWord(_value);
	}
	///////////

	static string LowerFirstLetterOfEachWord(string theString)
	{

		bool isFirstLetter = true;

		for (int i = 0; i < theString.length(); i++)
		{
			if (theString[i] != ' ' && isFirstLetter)
			{
				theString[i] = tolower(theString[i]);
			}

			isFirstLetter = (theString[i] == ' ' ? true : false);
		}

		return theString;
	}

	void LowerFirstLetterOfEachWord()
	{
		_value = LowerFirstLetterOfEachWord(_value);
	}
	///////////

	static string UpperAllString(string theString)
	{

		for (int i = 0; i < theString.length(); i++)
		{
			theString[i] = toupper(theString[i]);
		}
		return theString;
	}

	void UpperAllString()
	{
		_value = UpperAllString(_value);
	}
	///////////

	static string LowerAllString(string theString)
	{

		for (int i = 0; i < theString.length(); i++)
		{
			theString[i] = tolower(theString[i]);
		}
		return theString;
	}

	void LowerAllString()
	{
		_value = LowerAllString(_value);
	}
	///////////

	static char InvertLetterCase(char theChar)
	{
		return isupper(theChar) ? tolower(theChar) : toupper(theChar);
	}
	///////////

	static string InvertAllLettersCase(string theString)
	{
		for (int i = 0; i < theString.length(); i++)
		{
			theString[i] = InvertLetterCase(theString[i]);
		}
		return theString;
	}

	string InvertAllLettersCase()
	{
		_value = InvertAllLettersCase(_value);
	}
	//////////

	enum enWhatToCount { CapitalLetters = 0, SmallLetters = 1, All = 2 };

	static short CountLetters(string theString, enWhatToCount whatToCount = enWhatToCount::All)
	{

		if (whatToCount == enWhatToCount::All)
		{
			return theString.length();
		}

		short counter = 0;

		for (int i = 0; i < theString.length(); i++)
		{

			if (islower(theString[i]) && whatToCount == enWhatToCount::SmallLetters)
				counter++;
			else if (isupper(theString[i]) && whatToCount == enWhatToCount::CapitalLetters)
				counter++;

		}

		return counter;
	}
	//////////

	static short CountSmallLetters(string theString)
	{
		short counter = 0;

		for (int i = 0; i < theString.length(); i++)
		{
			if (islower(theString[i]))
				counter++;
		}
		return counter;
	}

	void CountSmallLetters()
	{
		_value = CountSmallLetters(_value);
	}
	//////////

	static short CountCapitalLetters(string theString)
	{
		short counter = 0;

		for (int i = 0; i < theString.length(); i++)
		{
			if (isupper(theString[i]))
				counter++;
		}
		return counter;
	}

	void CountCapitalLetters()
	{
		_value = CountCapitalLetters(_value);
	}
	/////////

	static short CountSpecificLetter(string theString, char theChar, bool matchCase = true)
	{

		short counter = 0;

		for (int i = 0; i < theString.length(); i++)
		{

			if (matchCase)
			{
				if (theString[i] == theChar)
					counter++;
			}
			else
			{
				if (tolower(theString[i]) == tolower(theChar))
				{
					counter++;
				}
			}

		}

		return counter;
	}

	short CountSpecificLetter(char letter, bool matchCase = true)
	{
		return CountSpecificLetter(_value, letter, matchCase);
	}
	/////////

	static bool IsVowel(char theChar)
	{

		theChar = tolower(theChar);

		return ((theChar == 'a') || (theChar == 'e') || (theChar == 'i') || (theChar == 'o') || (theChar == 'u'));

	}
	/////////

	static short CountVowels(string theString)
	{
		short counter = 0;

		for (int i = 0; i < theString.length(); i++)
		{
			if (IsVowel(theString[i]))
				counter++;
		}

		return counter;
	}

	short CountVowels()
	{
		return CountVowels(_value);
	}
	//////////
	static vector<string> Split(string S1, string delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			// if (sWord != "")
			// {
			vString.push_back(sWord);
			//}

			S1.erase(0, pos + delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}

	vector <string> Split(string delim)
	{
		return Split(_value, delim);
	}
	//////////

	static string TrimLeft(string str)
	{

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				return str.substr(i, str.length() - 1);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_value = TrimLeft(_value);
	}
	//////////

	static string TrimRight(string str)
	{

		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
			{
				return str.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight()
	{
		_value = TrimRight(_value);
	}
	//////////

	static string Trim(string str)
	{
		return TrimLeft(TrimRight(str));
	}

	void Trim()
	{
		_value = Trim(_value);
	}
	//////////

	static string JoinString(vector <string> vString, string delim)
	{

		string str = "";

		for (string& s : vString)
		{
			str += s + delim;
		}

		return str.substr(0, str.length() - delim.length());
	}
	/////////

	static string JoinString(string arrString[], int arrLength, string delim)
	{

		string str = "";

		for (int i = 0; i < arrLength; i++)
		{
			str += arrString[i] + delim;
		}

		return str.substr(0, str.length() - delim.length());
	}
	//////////

	static string ReverseWordsInString(string str)
	{


		vector <string> vString;
		string str2 = "";

		vString = Split(str, " ");

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			str2 += *iter + " ";

		}

		str2 = str2.substr(0, str2.length() - 1);


		return str2;
	}

	void ReverseWordsInString()
	{
		_value = ReverseWordsInString(_value);
	}
	//////////

	static string ReplaceWord(string str, string stringToReplace, string replaceTo, bool matchCase = true)
	{

		vector <string> vString;

		vString = Split(str, " ");


		for (string& s : vString)
		{

			if (matchCase)
			{
				if (s == stringToReplace)
					s = replaceTo;
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(stringToReplace))
				{
					s = replaceTo;
				}
			}

		}

		return JoinString(vString, " ");

	}

	string ReplaceWord(string stringToReplace, string replaceTo, bool matchCase = true)
	{
		return ReplaceWord(_value, replaceTo, matchCase);
	}
	//////////

	static string RemovePunctuations(string str)
	{

		string str2 = "";

		for (int i = 0; i < str.length(); i++)
		{
			if (!ispunct(str[i]))
			{
				str2 += str[i];
			}
		}

		return str2;
	}

	void RemovePunctuationsFromString()
	{
		_value = RemovePunctuations(_value);
	}

};