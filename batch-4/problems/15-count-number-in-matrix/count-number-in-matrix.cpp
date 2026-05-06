#include <iostream>

using namespace std;

int ReadNumber()
{
	int number;

	cout << "Please enter a number to count in matrix: " << endl;
	cin >> number;

	return number;
}

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

int main()
{

	int matrix[3][3] = { {9,3,0}, {0,9,3}, {4,9,9} };

	cout << "Matrix:\n";
	PrintMatrix(matrix, 3, 3);

	int num = ReadNumber();

	cout << "Number " << num << " count in matrix is "
		<< CountNumberInMatrix(matrix, 3, 3, num) << endl;

	return 0;
}