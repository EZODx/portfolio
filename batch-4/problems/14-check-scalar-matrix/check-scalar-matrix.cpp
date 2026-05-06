#include <iostream>

using namespace std;

void PrintMatrix(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d     ", arr[i][j]);
		}
		cout << endl;
	}
}

bool IsScalarMatrix(int matrix[3][3], short rows, short cols)
{

	int firstDiagElement = matrix[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			
			if (i == j && matrix[i][j] != firstDiagElement)
			{
				return false;
			}
			else if (i != j && matrix[i][j] != 0)
			{
				return false;
			}

		}
	}

	return true;
}

int main()
{

	int matrix[3][3] = { {9,0,0}, {0,9,0}, {0,0,9} };

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);

	if (IsScalarMatrix(matrix, 3, 3))
		cout << "\nYes, the matrix are scalar\n";
	else
		cout << "\nNo , the matrix are NOT scalar\n";

	return 0;
}