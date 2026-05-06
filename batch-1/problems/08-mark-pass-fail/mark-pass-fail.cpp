#include <iostream>

using namespace std;

enum PassFail { Pass = 1, Fail = 2 };

float ReadMark()
{
	float Mark;

	cout << "Please enter the mark: " << endl;
	cin >> Mark;
	return Mark;
}

PassFail PassOrFailed(float Mark)
{
	if (Mark >= 50)
		return PassFail::Pass;
	else
		return PassFail::Fail;

}

void PrintResult(float Mark)
{
	if (PassOrFailed(Mark) == PassFail::Pass)
		cout << "You passed" << endl;
	else
		cout << "Failed" << endl;
}

int main()
{
	PrintResult((ReadMark());

	return 0;
}