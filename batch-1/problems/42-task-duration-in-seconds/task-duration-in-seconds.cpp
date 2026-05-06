#include <iostream>

using namespace std;

struct stTaskDuration { int NumberOfDays, NumbersOfHours, NumberOfMinutes, NumberOfSeconds; };

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	}
	while (Number <= 0);

	return Number;
}

stTaskDuration ReadTaskDuration()
{
	stTaskDuration TaskDuration;

	TaskDuration.NumberOfDays = ReadPositiveNumber("Please enter number of days : ");
	TaskDuration.NumbersOfHours = ReadPositiveNumber("Please enter number of hours : ");
	TaskDuration.NumberOfMinutes = ReadPositiveNumber("Please enter number of minutes : ");
	TaskDuration.NumberOfSeconds = ReadPositiveNumber("Please enter number of seconds : ");

	return TaskDuration;
}

float TaskDurationInSeconds(stTaskDuration TaskDuration)
{
	int DurationInSeconds;

	DurationInSeconds = TaskDuration.NumberOfDays * 60 * 60 * 24;
	DurationInSeconds += TaskDuration.NumbersOfHours * 60 * 60;
	DurationInSeconds += TaskDuration.NumberOfMinutes * 60;
	DurationInSeconds += TaskDuration.NumberOfSeconds;

	return DurationInSeconds;
}

int main()
{
	cout << "\nTask duration in seconds = " << TaskDurationInSeconds(ReadTaskDuration()) << endl;

	return 0;
}