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

int MinimumNumberInMatrix(int matrix[3][3], short rows, short cols)
{

	int minValue = matrix[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] < minValue)
				minValue = matrix[i][j];
		}
	}

	return minValue;
}

int MaxNumberInMatrix(int matrix[3][3], short rows, short cols)
{

	int maxValue = matrix[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] > maxValue)
				maxValue = matrix[i][j];
		}
	}

	return maxValue;
}

int main()
{

	int matrix[3][3] = { {21,77,0}, {113,1,8}, {4,8,9} };

	cout << "Matrix 1:\n";
	PrintMatrix(matrix, 3, 3);


	cout << "\nThe mimimum number is: "
		<< MinimumNumberInMatrix(matrix, 3, 3) << endl;

	cout << "\nThe Max number is: "
		<< MaxNumberInMatrix(matrix, 3, 3) << endl;

	return 0;
}