#include <iostream>

using namespace std;

// Inheritance visability modes

class clsA
{

private:
    int _var1;
    void _Fun1()
    {
        cout << "Function 1" << endl;
    }


protected:
    int var2;

    void Fun2()
    {
        cout << "Function 2" << endl;
    }


public:
    int var3;

    void Fun3()
    {
        cout << "Function 3" << endl;
    } 



};

class clsB : protected clsA
{

public:
    void fun1()
    {

    }

};

class clsC : public clsB
{

public:
    void func1()
    {
        
    }
    
};

class clsD : private clsB
{
public:
    void function1()
    {

    }
};


int main()
{

    clsC c1;
    clsD d1;

    c1.fun1();

    d1.function1();

    return 0;
}