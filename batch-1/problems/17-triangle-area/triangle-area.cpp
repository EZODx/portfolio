#include <iostream>

using namespace std;

void ReadNumbers(float& A, float& H)
{
	cout << "Please enter triangle base A : " << endl;
	cin >> A;
	cout << "Please enter triangle height H : " << endl;
	cin >> H;
}

float TriangleArea(float A, float H)
{
	float Area = (0.5 * A) * H;

	return Area;
}

void PrintResutl(float Area)
{
	cout << "\nTriangle Area = " << Area << endl;
}

int main()
{
	float A, H;
	ReadNumbers(A, H);
	PrintResutl(TriangleArea(A, H));

	return 0;
}