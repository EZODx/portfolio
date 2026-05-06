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

bool IsIdentityMatrix(int matrix[3][3], short rows, short cols)
{

	//check Diagonal elements are 1 and rest elements are 0

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			//check for diagonals element
			if (i == j && matrix[i][j] != 1)
			{
				return false;
			}
			//check for rest elements
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

	int matrix[3][3] = { {1,0,0}, {0,1,0}, {0,0,1} };

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);

	if (IsIdentityMatrix(matrix, 3, 3))
		cout << "\nYes, the matrix are identity\n";
	else
		cout << "\nNo , the matrix are NOT identity\n";

	return 0;
}