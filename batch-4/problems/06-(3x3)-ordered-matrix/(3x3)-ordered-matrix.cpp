#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << left << setw(3) << arr[i][j] << "   ";
		}
		cout << endl;
	}
}

void FillMatrixWithOrderedNumbers(int arr[3][3], short rows, short cols)
{
	
	short Counter = 1;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = Counter;
			Counter++;
		}
	}

}

int main()
{

	int arr[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);

	cout << "The following is a 3x3 ordered matrix:\n";
	PrintMatrix(arr, 3, 3);

	return 0;
}