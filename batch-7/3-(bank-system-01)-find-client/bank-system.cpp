#include <iostream>
#include "clsBankClient.h"

int main()
{

    clsBankClient client1 = clsBankClient::Find("A101");
    if (!client1.IsEmpty())
    {
        cout << "\nClient found :-)\n";
    }
    else
    {
        cout << "\nClient not found :-(\n";
    }

    client1.Print();

    clsBankClient client2 = clsBankClient::Find("A101", "1234");
    if (!client2.IsEmpty())
    {
        cout << "\nClient found :-)\n";
    }
    else
    {
        cout << "\nClient not found :-(\n";
    }

    client2.Print();

    cout << "Does client exist? " << clsBankClient::DoesClientExist("A101") << endl;

    return 0;
}