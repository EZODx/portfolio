#include <iostream>

using namespace std;

class clsCalculator
{
private:
    float _result = 0;
    float _operationNumber = 0;
    char _operationType = ' ';



public:
    void Add(float number)
    {
        _result = _result + number;
        _operationType = '+';
        _operationNumber = number;
    }

    void Subtract(float number)
    {
        _result = _result - number;
        _operationType = '-';
        _operationNumber = number;

    }

    void Divide(float number)
    {
        if (number == 0)
            number = 1;
        _result = _result / number;
        _operationType = '/';
        _operationNumber = number;
    }

    void Multiply(float number)
    {
        _result = _result * number;
        _operationType = '*';
        _operationNumber = number;

    }

    void Clear()
    {
        _result = 0;
        _operationType = ' ';
    }

    void PrintResult()
    {

        switch (_operationType)
        {
        case '+':
            cout << "The result after adding " << _operationNumber << " is: " << _result << endl;
            break;
        case '-':
            cout << "The result after subtracting " << _operationNumber << " is: " << _result << endl;
            break;
        case '/':
            cout << "The result after dividing " << _operationNumber << " is: " << _result << endl;
            break;
        case '*':
            cout << "The result after multiplying by " << _operationNumber << " is: " << _result << endl;
            break;
        default:
            cout << "The result after clearing is: " << _result << endl;
        }
    }

};

int main()
{

    clsCalculator calculator;

    calculator.Clear();

    calculator.Add(10);
    calculator.PrintResult();

    calculator.Add(100);
    calculator.PrintResult();

    calculator.Subtract(60);
    calculator.PrintResult();

    calculator.Multiply(2);
    calculator.PrintResult();

    calculator.Divide(2);
    calculator.PrintResult();

    calculator.Divide(0);
    calculator.PrintResult();

    calculator.Clear();
    calculator.PrintResult();

    return 0;
}
