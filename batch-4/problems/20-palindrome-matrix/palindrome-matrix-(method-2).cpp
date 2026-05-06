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

bool IsPalindromeMatrix(int matrix[3][3], short rows, short cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols / 2; j++)
		{
			if (matrix[i][j] != matrix[i][cols - 1 - j])
				return false;
		}
	}

	return true;
}

int main()
{

	int matrix[3][3] = { {1,77,1}, {113,1,113}, {4,4,4} };

	cout << "Matrix 1:\n";
	PrintMatrix(matrix, 3, 3);

	if (IsPalindromeMatrix(matrix, 3, 3))
		cout << "\nYes, the matrix is palindrome\n";
	else
		cout << "\nNo, the matrix is NOT palindrome\n";


	return 0;
}