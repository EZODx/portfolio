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

	friend class clsB; // This line allows clsB to access private and protected members of clsA

};

class clsB : public clsA
{

public:
	void Display(clsA A)
	{
		cout << "The value of var1 : " << A._var1 << endl;
		cout << "The value of var2 : " << A.var2 << endl;
		cout << "The value of var3 : " << A.var3 << endl;
	}

};

int main()
{
	clsA A1;
	clsB B1;

	B1.Display(A1);

	return 0;
}