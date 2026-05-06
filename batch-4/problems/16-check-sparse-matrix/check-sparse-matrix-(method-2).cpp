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

short CountNumberInMatrix(int matrix[3][3], short rows, short cols, int num)
{

	short numberCounter = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == num)
			{
				numberCounter++;
			}
		}
	}

	return numberCounter;
}

bool IsSparceMatrix(int matrix[3][3], short rows, short cols)
{

	short matrixSize = rows * cols;

	return (CountNumberInMatrix(matrix, 3, 3, 0) > (matrixSize/2));

}

int main()
{

	int matrix[3][3] = { {12,0,0}, {0,0,3}, {4,8,9} };

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);


	if (IsSparceMatrix(matrix, 3, 3))
		cout << "\nYes, it's sparce\n";
	else
		cout << "\nNo, it's NOT sparce\n";

	return 0;
}