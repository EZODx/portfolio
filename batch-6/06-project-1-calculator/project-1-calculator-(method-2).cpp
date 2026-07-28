#include <iostream>

using namespace std;

class clsCalculator
{
private:
    float _result = 0;
    float _lastNumber = 0;
    string _lastOperation = "Clear";
    float _previousResult = 0;

    bool _isZero(float number)
    {
        return (number == 0);
    }


public:

    void Add(float number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _lastOperation = "adding";
        _result += number;

    }
    void Subtract(float number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _lastOperation = "subtracting";
        _result -= number;
    }
    void Divide(float number)
    {
        _lastNumber = number;

        if (_isZero(number))
        {
            number = 1;
        }

        _previousResult = _result;
        _lastOperation = "dividing";
        _result /= number;
    }
    void Multiply(float number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _lastOperation = "multipling";
        _result *= number;
    }

    void Clear()
    {
        _lastNumber = 0;
        _previousResult = 0;
        _lastOperation = "Clear";
        _result = 0;
    }

    float GetFinalResult()
    {
        return _result;
    }

    void CancelLastOperation()
    {
        _result = _previousResult;
        _lastOperation = "canceling last operation";
        _lastNumber = 0;
    }

    void PrintResult()
    {

        cout << "The result after ";
        cout << _lastOperation << " " << _lastNumber << " is: " << _result << endl;
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

    calculator.Subtract(10);
    calculator.PrintResult();

    calculator.Multiply(10);
    calculator.PrintResult();

    calculator.Divide(0);
    calculator.PrintResult();

    calculator.Divide(2);
    calculator.PrintResult();

    calculator.CancelLastOperation();
    calculator.PrintResult();

    calculator.Clear();
    calculator.PrintResult();

    return 0;
}
