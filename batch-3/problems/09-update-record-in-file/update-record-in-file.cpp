#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void PrintFileContent(string fileName)
{

	fstream myFile;
	myFile.open(fileName, ios::in);

	if (myFile.is_open())
	{
		string line;

		while (getline(myFile, line))
		{
			cout << line << endl;
		}

		myFile.close();
	}

}

void LoadDataFromFileToVector(string fileName, vector <string> &vFileContent)
{

	fstream myFile;
	myFile.open(fileName, ios::in);

	if (myFile.is_open())
	{

		string line;

		while (getline(myFile, line))
		{
			vFileContent.push_back(line);
		}

		myFile.close();
	}

}

void SaveVectorToFile(string fileName, vector <string> vFileContent)
{

	fstream myFile;
	myFile.open(fileName, ios::out);

	if (myFile.is_open())
	{

		for (string line : vFileContent)
		{
			if (line != "")
			{
				myFile << line << endl;
			}
		}

		myFile.close();
	}

}

void UpdateFileContent(string fileName, string record, string updateTo)
{

	vector <string> vFileContent;
	LoadDataFromFileToVector(fileName, vFileContent);


	for (string& line : vFileContent)
	{
		if (line == record)
		{
			line = updateTo;
		}
	}

	SaveVectorToFile(fileName, vFileContent);
}

int main()
{

	cout << "File content before delete:" << endl;
	PrintFileContent("myFile.txt");

	UpdateFileContent("myFile.txt", "Ali", "Omar");

	cout << "\n\nFile content after delete:" << endl;
	PrintFileContent("myFile.txt");

	return 0;
}
