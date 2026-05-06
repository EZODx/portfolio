#include <iostream>
#include <iomanip>

using namespace std;

int ReadNumber()
{
	int number;

	cout << "Please enter a number to search for in the matrix: " << endl;
	cin >> number;

	return number;
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << left << setw(3) << matrix[i][j] << "   ";
		}
		cout << endl;
	}
}

bool IsNumberInMatrix(int matrix[3][3], short rows, short cols, short num)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == num)
				return true;
		}
	}

	return false;
}

int main()
{

	int matrix[3][3] = { {12,0,0}, {0,0,3}, {4,8,9} };

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);

	short num = ReadNumber();

	if (IsNumberInMatrix(matrix, 3, 3, num))
		cout << "\nYes it is in there\n";
	else
		cout << "\nNo, it is NOT in there\n";


	return 0;
}