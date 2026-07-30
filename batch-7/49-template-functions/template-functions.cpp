#include <iostream>

using namespace std;

template <typename T> T MyMax(T number1, T number2, string message)
{
    cout << message;
    return (number1 > number2) ? number1 : number2;
}

int main()
{
    
	cout << MyMax<int>(10, 20, "The maximum number is: ") << endl;

    cout << MyMax<float>(5.5, 4.4, "The maximum number is: ") << endl;

	cout << MyMax<char>('a', 'b', "The maximum character is: ") << endl;

    return 0;
}