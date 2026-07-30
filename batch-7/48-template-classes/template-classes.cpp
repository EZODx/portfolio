#include <iostream>

using namespace std;

template <class T>
class Calculator
{

private:

    T _num1, _num2;

public:

    Calculator(T num1, T num2)
    {
        _num1 = num1;
        _num2 = num2;
    }

    void PrintResults()
    {
        cout << "The numbers are: 1: (" << _num1 << ") 2: (" << _num2 << ")" << endl;
        cout << _num1 << " + " << _num2 << " = " << Add() << endl;
        cout << _num1 << " - " << _num2 << " = " << Subtract() << endl;
        cout << _num1 << " * " << _num2 << " = " << Multiply() << endl;
        cout << _num1 << " / " << _num2 << " = " << Subtract() << endl;
    }

    T Add()
    {
        return _num1 + _num2;
    }

    T Subtract()
    {
        return _num1 - _num2;
    }

    T Multiply()
    {
        return _num1 * _num2;
    }

    T Divide()
    {
        return _num1 / _num2;
    }

};

int main()
{

    Calculator <int> intCalc(10, 5);

    Calculator <float> floatCalc(4.2, 2.1);

    cout << "Int Results:" << endl;
    intCalc.PrintResults();
    
    cout << "\nFloat Results:" << endl;
    floatCalc.PrintResults();

    return 0;
}