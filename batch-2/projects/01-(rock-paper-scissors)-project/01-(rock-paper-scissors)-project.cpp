#include <iostream>
#include <cstdlib>

using namespace std;

enum enOption { Stone = 1, Paper = 2, scissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stGameResults
{
	int NumberOfRounds =0;
	int Player1WinTimes =0;
	int ComputerWinTimes =0;
	int DrawTimes =0;
	enWinner GameWinner;
	string WinnerName = "";
};

struct stRoundInfo
{
	short NumberOfRound=0;
	enOption Player1Choice;
	enOption ComputerChoice;
	enWinner RoundWinner;
	string WinnerName = "";
};

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

enOption ReadPlayer1Choice()
{
	short TheChoice;
	do
	{
		cout << "Choose your option : [1]: Stone, [2]: Paper, [3]: scissors : ";
		cin >> TheChoice;
	} while (TheChoice < 1 || TheChoice > 3);


	return (enOption)TheChoice;
}

enOption GetComputerChoice()
{
	return (enOption)RandomNumber(1, 3);
}

enWinner RoundWinner(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		system("color 6F");
		return enWinner::Draw;
	}



	switch (RoundInfo.Player1Choice)
	{
		
	case enOption::Paper:
		if (RoundInfo.ComputerChoice == enOption::scissors)
		{
		system("color 4F");
		cout << "\a";
		return enWinner::Computer;
		}
		break;
	case enOption::Stone:
		if (RoundInfo.ComputerChoice == enOption::Paper)
		{
			system("color 4F");
			cout << "\a";
			return enWinner::Computer;
		}
		break;
	case enOption::scissors:
		if (RoundInfo.ComputerChoice == enOption::Stone)
		{
			system("color 4F");
			cout << "\a";
			return enWinner::Computer;
		}
		break;

	}

	// if you reach here, then player1 is the winner
	system("color 2F");
	return enWinner::Player1;

}

short HowManyRounds()
{
	short NumberOfRounds;
	do
	{
		cout << "How many rounds do you want you play (1-10)? : ";
		cin >> NumberOfRounds;
	} while (NumberOfRounds < 1 || NumberOfRounds > 10);
	
	return NumberOfRounds;
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName [3] = {"Player1", "Computer", "No winner"};
	return arrWinnerName[Winner - 1];
}

string Choice(enOption Info)
{
	string arrChoice[3] = { "Stone", "Paper", "scissors" };
	return arrChoice[Info - 1];
}

void ShowRoundResult(stRoundInfo RoundInfo)
{

	cout << "\n_____________ Round[" << RoundInfo.NumberOfRound << "] ________________\n\n";
	cout << "Player1 choice  : " << Choice(RoundInfo.Player1Choice) << endl;
	cout << "Computer choice : " << Choice(RoundInfo.ComputerChoice) << endl;
	cout << "Round winner    : [" << RoundInfo.WinnerName << "]" << endl;
	cout << "__________________________________________\n\n";
}

enWinner GameWinner(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

stGameResults FillGameResults(short Player1WinTimes, short ComputerWinTimes, short Draw, short NumberOfRounds)
{
	stGameResults GameResults;

	GameResults.NumberOfRounds = NumberOfRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = Draw;
	GameResults.GameWinner = GameWinner(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;

}

string Taps(int NumberOfTaps)
{
	string t = "";

	for (int i = 1; i <= NumberOfTaps; i++)
	{
		t += "\t";
	}

	return t;
}

void ShowGameOverResult()
{
	
	cout << Taps(2) << "____________________________________________________\n\n";
	cout << Taps(2) << "               +++ G a m e O v e r +++              \n\n";
	cout << Taps(2) << "____________________________________________________\n\n";

}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
		case enWinner::Player1:
		system("color 2F");
		break;

		case enWinner::Computer:
			system("color 4F");
			cout << "\a";
			break;

		case enWinner::Draw:
			system("color 6F");
			break;
	}

}

void ShowGameResults(stGameResults GameResults)
{
	cout << Taps(2) << "__________________ [Game Results] __________________\n\n";
	cout << Taps(2) << "Game rounds        : " << GameResults.NumberOfRounds << endl;
	cout << Taps(2) << "Player1 won times  : " << GameResults.Player1WinTimes << endl;
	cout << Taps(2) << "Computer won times : " << GameResults.ComputerWinTimes << endl;
	cout << Taps(2) << "Draw times         : " << GameResults.DrawTimes << endl;
	cout << Taps(2) << "Final winner       : [" << WinnerName(GameResults.GameWinner) << "]" << endl;
	cout << Taps(2) << "___________________________________________________\n";

	SetWinnerScreenColor(GameResults.GameWinner);

}

stGameResults PlayGame(short NumberOfRounds)
{
	stRoundInfo RoundInfo;

	short Player1WinTimes = 0, ComputerWinTimes = 0, Draw = 0;

	for (int GameRound = 1; GameRound <= NumberOfRounds; GameRound++)
	{
		cout << "\nRound[" << GameRound << "] Begin :\n\n";
		RoundInfo.NumberOfRound = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.RoundWinner = RoundWinner(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.RoundWinner);


		if (RoundInfo.RoundWinner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.RoundWinner == enWinner::Computer)
			ComputerWinTimes++;
		else
			Draw++;

		ShowRoundResult(RoundInfo);

	}

	return FillGameResults(Player1WinTimes, ComputerWinTimes, Draw, NumberOfRounds);
}

void ResetScreen()
{
	system("color 0F");
	system("cls");
}

void StartGame()
{

	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(HowManyRounds());
		ShowGameOverResult();
		ShowGameResults(GameResults);

		cout << endl << Taps(2) << "Do you want to play again (Y/N)? : ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}