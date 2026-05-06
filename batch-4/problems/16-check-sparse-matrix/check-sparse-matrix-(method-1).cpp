#include <iostream>
#include <iomanip>

using namespace std;

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

bool IsSparceMatrix(int matrix[3][3], short rows, short cols)
{
	short zerosCounter = 0, noneZeroCounter = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			if (matrix[i][j] == 0)
			{
				zerosCounter++;
			}
			else
			{
				noneZeroCounter++;
			}

		}
	}

	if (zerosCounter > noneZeroCounter)
		return true;
	else
		return false;


}

int main()
{

	int matrix[3][3] = { {12,0,0}, {0,0,0}, {4,0,9} };

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);


	if (IsSparceMatrix(matrix, 3, 3))
		cout << "\nYes, it's sparce\n";
	else
		cout << "\nNo, it's NOT sparce\n";

	return 0;
}