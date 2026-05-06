#include <iostream>

using namespace std;

struct stInfo
{
	int age;
	bool HasDrivingLicense;
};

stInfo ReadPersonInfo()
{
	stInfo Info;
	cout << "Please enter your age: " << endl;
	cin >> Info.age;
	cout << "Do you have driving license ? : " << endl;
	cin >> Info.HasDrivingLicense;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	return (Info.age >= 21 && Info.HasDrivingLicense == 1);
}

void PrintResult(stInfo Inof)
{
	if (IsAccepted(Inof))
	{
		cout << "Hired" << endl;
	}
	else
	{
		cout << "Rejected" << endl;
	}
}

int main()
{
	PrintResult(ReadPersonInfo());

	return 0;
}