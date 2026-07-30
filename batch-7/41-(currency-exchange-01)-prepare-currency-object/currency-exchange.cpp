#include <iostream>
#include "clsCurrency.h"

void PrintCurrency(clsCurrency currency)
{
    cout << "Currency Card:\n";
    cout << "_________________________\n";
    cout << "Country  : " << currency.Country() << endl;
    cout << "Code     : " << currency.CurrencyCode() << endl;
    cout << "Name     : " << currency.CurrencyName() << endl;
    cout << "Rate(1$) : " << currency.Rate() << endl;
    cout << "_________________________\n\n";

}

int main()
{

    clsCurrency currency1 = currency1.FindByCode("COP");

    if (currency1.IsEmpty())
    {
        cout << "Currency not found!\n";
    }
    else
    {
        PrintCurrency(currency1);
    }

    clsCurrency currency2 = currency2.FindByCountry("Colombia");

    if (currency2.IsEmpty())
    {
        cout << "Currency not found!\n";
    }
    else
    {
        PrintCurrency(currency2);
    }

    currency1.UpdateRate(5);
    cout << "\n\nCurrency 1 after update the rate:\n";
    PrintCurrency(currency1);

    return 0;
}