#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void LoadDataFromFileToVector(string FileName, vector <string> &vFileContent)
{

	fstream myFile;
	myFile.open(FileName, ios::in);

	string line;

	if (myFile.is_open())
	{

		while (getline(myFile, line))
		{
			vFileContent.push_back(line);
		}

		myFile.close();
	}

}

int main()
{

	vector <string> vFileContent;

	LoadDataFromFileToVector("myFile.txt", vFileContent);

	for (string& line : vFileContent)
	{
		cout << line << endl;
	}

	return 0;
}
