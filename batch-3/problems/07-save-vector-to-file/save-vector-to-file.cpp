#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void SaveVectorToFile(string fileName, vector <string> vFileContent)
{

	fstream myFile;

	myFile.open(fileName, ios::out);

	if (myFile.is_open())
	{

		for (string& line : vFileContent)
		{
			if (line != "")
			{
				myFile << line << endl;
			}
		}

		myFile.close();
	}

}

int main()
{

	vector <string> vFileContent = { "EZOD", "Nova", "Lila", "June", "Max" };

	SaveVectorToFile("myFile.txt", vFileContent);


	return 0;
}
