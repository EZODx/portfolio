#include <iostream>
#include <iomanip>
#include <string>

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

	string line1A = to_string(matrix[0][0]) + to_string(matrix[0][1]) + to_string(matrix[0][2]);
	string line1B = to_string(matrix[0][2]) + to_string(matrix[0][1]) + to_string(matrix[0][0]);

	string line2A = to_string(matrix[1][0]) + to_string(matrix[1][1]) + to_string(matrix[1][2]);
	string line2B = to_string(matrix[1][2]) + to_string(matrix[1][1]) + to_string(matrix[1][0]);

	string line3A = to_string(matrix[2][0]) + to_string(matrix[2][1]) + to_string(matrix[2][2]);
	string line3B = to_string(matrix[2][2]) + to_string(matrix[2][1]) + to_string(matrix[2][0]);

	if (line1A == line1B && line2A == line2B && line3A == line3B)
		return true;
	else
		return false;

}

int main()
{

	int matrix[3][3] = { {1,77,1}, {113,1,113}, {4,4,4} };

	cout << "Matrix 1:\n";
	PrintMatrix(matrix, 3, 3);

	if (IsPalindromeMatrix(matrix, 3, 3))
		cout << "Yes, the matrix is palindrome\n";
	else
		cout << "No, the matrix is NOT palindrome\n";


	return 0;
}