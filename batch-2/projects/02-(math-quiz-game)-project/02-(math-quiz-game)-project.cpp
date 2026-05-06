#include <iostream>
#include <cstdlib>

using namespace std;

enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };

enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOT };

struct stQuestion
{
	short Number1;
	short Number2;
	enQuestionsLevel QuestionLevel;
	enOperationType OperationType;
	short CorrectAnswer;
	short PlayerAnswer;
	bool AnswerResult;

};

struct stQuiz
{
	stQuestion QuizQuestions[100];
	short NumberOfQuestions;
	enQuestionsLevel QuizLevel;
	enOperationType QuizOT;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool IsPassed;
};

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

short ReadNumberOfQuestions()
{
	short NumberOfQuestions;
	do
	{
		cout << "Please enter the number of questions (1-10): ";
		cin >> NumberOfQuestions;
	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);

	return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short QuestionsLevel;

	do
	{
		cout << "Please enter the question level [1]:Easy,[2]:Med, [3]:Hard, [4]:Mix: ";
		cin >> QuestionsLevel;
	} while (QuestionsLevel < 1 || QuestionsLevel > 4);

	return (enQuestionsLevel)QuestionsLevel;
}

enOperationType ReadOperationType()
{
	short OT;

	do
	{
		cout << "Please enter the operation type [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix ";
		cin >> OT;
	} while (OT < 1 || OT > 5);
	
	return (enOperationType)OT;
}

enOperationType GenerateOT()
{
	short OT = RandomNumber(1, 4);
	return (enOperationType)OT;
}

short SimpleCalculate(short Number1, short Number2, enOperationType OT)
{

	switch (OT)
	{
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Mul:
		return Number1 * Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionsLevel, enOperationType OT)
{
	stQuestion Question;

	if (QuestionsLevel == enQuestionsLevel::Mix)
	{
		QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
	}

	if (OT == enOperationType::MixOT)
	{
		OT = GenerateOT();
	}

	Question.QuestionLevel = QuestionsLevel;

	switch (QuestionsLevel)
	{
		case enQuestionsLevel::EasyLevel:
		{
			Question.Number1 = RandomNumber(1, 10);
			Question.Number2 = RandomNumber(1, 10);
			return Question;
		}
		case enQuestionsLevel::MedLevel:
		{
			Question.Number1 = RandomNumber(10, 50);
			Question.Number2 = RandomNumber(10, 50);
			return Question;
		}
		case enQuestionsLevel::HardLevel:
		{
			Question.Number1 = RandomNumber(50, 100);
			Question.Number2 = RandomNumber(50, 100);
			return Question;
		}
	}

	Question.CorrectAnswer = SimpleCalculate(Question.Number1, Question.Number2, OT);
	Question.OperationType = OT;

}

void GenerateQuizQuestions(stQuiz& Quiz)
{

	for (int Question = 0; Question < Quiz.NumberOfQuestions; Question++)
	{
		Quiz.QuizQuestions[Question] = GenerateQuestion(Quiz.QuizLevel, Quiz.QuizOT);
	}

}

string GetOTSymbol(enOperationType OT)
{

	switch (OT)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Sub:
		return "-";
	case enOperationType::Mul:
		return "*";
	case enOperationType::Div:
		return "/";
	default:
		return "Mix";
	}

}

void PrintTheQuestion(stQuiz& Quiz, short QuestionNumber)
{

	cout << "\nQuestion [" << QuestionNumber + 1 << "/" << Quiz.NumberOfQuestions << "]\n\n";
	cout << Quiz.QuizQuestions[QuestionNumber].Number1 << endl;
	cout << Quiz.QuizQuestions[QuestionNumber].Number2 << " ";
	cout << GetOTSymbol(Quiz.QuizQuestions[QuestionNumber].OperationType);
	cout << "\n________\n";

}

void SetScreenColor(bool TheAnswer)
{

	switch (TheAnswer)
	{
	case true:
		system("color 2F");
		break;
	case false:
		system("color 4F");
		break;
	}

}

short ReadAnswer()
{
	short Answer;
	cin >> Answer;
	return Answer;
}

void AnswerResult(stQuiz& Quiz, short QuestionNumber)
{
	if (Quiz.QuizQuestions[QuestionNumber].PlayerAnswer != Quiz.QuizQuestions[QuestionNumber].CorrectAnswer)
	{
		Quiz.QuizQuestions[QuestionNumber].AnswerResult = false;	
		Quiz.NumberOfWrongAnswers++;

		cout << "\nYour answer is wrong :(\n";
		cout << "The right answer is: ";
		cout << Quiz.QuizQuestions[QuestionNumber].CorrectAnswer;
		cout << "\a";
		cout << endl;
	}
	else
	{
		Quiz.QuizQuestions[QuestionNumber].AnswerResult = true;
		Quiz.NumberOfRightAnswers++;

		cout << "\nYour answer is right :)\n\n";
	}

	SetScreenColor(Quiz.QuizQuestions[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionsListAnswers(stQuiz& Quiz)
{

	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		PrintTheQuestion(Quiz, QuestionNumber);

		Quiz.QuizQuestions[QuestionNumber].PlayerAnswer = ReadAnswer();

		AnswerResult(Quiz, QuestionNumber);
	}

	Quiz.IsPassed = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);

}

string GetIsPassText(bool IsPassed)
{
	if (IsPassed)
		return "Passed :)";
	else
		return "Failed :(";
}

string GetQuestionsLevelText(enQuestionsLevel QuestionLevel)
{
	
	string QuestionsLevel[4] = { "Easy", "Med", "Hard", "Mix" };
	return QuestionsLevel[QuestionLevel - 1];

}

void PrintTheFinalResult(stQuiz& Quiz)
{

	cout << "\n______________________________\n\n";
	cout << "  Final result is  " << GetIsPassText(Quiz.IsPassed) << endl;
	cout << "\n______________________________\n";
	cout << "\nNumber of question      : " << Quiz.NumberOfQuestions;
	cout << "\nThe questions level     : " << GetQuestionsLevelText(Quiz.QuizLevel);
	cout << "\nThe Operation type      : " << GetOTSymbol(Quiz.QuizOT);
	cout << "\nNumber of right answers : " << Quiz.NumberOfRightAnswers;
	cout << "\nNumber of wrong answers : " << Quiz.NumberOfWrongAnswers << endl;

}

void PlayMathGame()
{

	stQuiz Quiz;

	Quiz.NumberOfQuestions = ReadNumberOfQuestions();
	Quiz.QuizLevel = ReadQuestionsLevel();
	Quiz.QuizOT = ReadOperationType();

	GenerateQuizQuestions(Quiz);
	AskAndCorrectQuestionsListAnswers(Quiz);
	PrintTheFinalResult(Quiz);

}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartQuiz()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		PlayMathGame();

		cout << endl << "Do you want to play again? (Y/N): ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{

	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	StartQuiz();

	return 0;
}