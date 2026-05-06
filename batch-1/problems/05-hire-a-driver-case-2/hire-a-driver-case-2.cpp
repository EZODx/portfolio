#include <iostream>

using namespace std;

struct stInfo
{
	int age;
	bool HasDrivingLicense;
	bool HasRecommendation;
};

stInfo ReadPersonInfo()
{
	stInfo Info;
	cout << "Please enter your age: " << endl;
	cin >> Info.age;
	cout << "Do you have driving license ? : " << endl;
	cin >> Info.HasDrivingLicense;
	cout << "Do you have Recommendation ? : " << endl;
	cin >> Info.HasRecommendation;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	if (Info.HasRecommendation)
	{
		return true;
	}
	else
	{
		return (Info.age >= 21 && Info.HasDrivingLicense == 1);
	}
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