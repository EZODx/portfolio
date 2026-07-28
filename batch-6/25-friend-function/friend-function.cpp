#include <iostream>

using namespace std;

class clsA
{
private:
	int _var1;

protected:
	int var2;

public:
	int var3;

	clsA()
	{
		_var1 = 10;
		var2 = 20;
		var3 = 30;
	}

	friend int MySum(clsA A); // friend function can access private and protected members of the class

};

int MySum(clsA A)
{
	return A._var1 + A.var2 + A.var3;
}

int main()
{

	clsA A1;

	cout << MySum(A1) << endl;

	return 0;
}