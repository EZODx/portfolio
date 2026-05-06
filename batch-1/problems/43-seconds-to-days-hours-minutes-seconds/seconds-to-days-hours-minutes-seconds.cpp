#include <iostream>

using namespace std;

struct stTaskDuration { int NumberOfDays, NumberOfHours, NumberOFMinutes, NumberOfSeconds; };

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

stTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
	stTaskDuration TaskDuration;
	const int SecondsPerDay = 24 * 60 * 60;
	const int SecondsPerHours = 60 * 60;
	const int SecondsPerMinutes = 60;

	int Reminder;
	TaskDuration.NumberOfDays = floor(TotalSeconds / SecondsPerDay);
	Reminder = TotalSeconds % SecondsPerDay;
	TaskDuration.NumberOfHours = floor(Reminder / SecondsPerHours);
	Reminder = Reminder % SecondsPerHours;
	TaskDuration.NumberOFMinutes = floor(Reminder / SecondsPerMinutes);
	Reminder = Reminder % SecondsPerMinutes;
	TaskDuration.NumberOfSeconds = Reminder;

	return TaskDuration;
}

void PrintTaskDurationDetails(stTaskDuration TaskDuration)
{
	cout << TaskDuration.NumberOfDays << ":"
		<< TaskDuration.NumberOfHours << ":"
		<< TaskDuration.NumberOFMinutes << ":"
		<< TaskDuration.NumberOfSeconds << endl;
}

int main()
{

	int NumberOfSeconds = ReadPositiveNumber("Please enter number of seconds");

	PrintTaskDurationDetails(SecondsToTaskDuration(NumberOfSeconds));

	return 0;
}