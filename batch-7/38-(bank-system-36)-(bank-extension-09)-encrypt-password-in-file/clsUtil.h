#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:
    enum enCharType
    {
        smallLetter = 1, capitalLetter = 2,
        digit = 3, mixChars = 4, specialCharacter = 5
    };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int from, int to)
    {
        //Function to generate a random number
        int randNum = rand() % (to - from + 1) + from;
        return randNum;
    }

    static char GetRandomCharacter(enCharType charType)
    {

        //updated this method to accept mixchars
        if (charType == mixChars)
        {
            //Capital/Small/Digits only
            charType = (enCharType)RandomNumber(1, 3);

        }

        switch (charType)
        {

        case enCharType::smallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::capitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::specialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        default:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static  string GenerateWord(enCharType charType, short length)

    {
        string word;

        for (int i = 1; i <= length; i++)

        {

            word = word + GetRandomCharacter(charType);

        }
        return word;
    }

    static string  GenerateKey(enCharType charType = capitalLetter)
    {

        string key = "";


        key = GenerateWord(charType, 4) + "-";
        key = key + GenerateWord(charType, 4) + "-";
        key = key + GenerateWord(charType, 4) + "-";
        key = key + GenerateWord(charType, 4);


        return key;
    }

    static void GenerateKeys(short numberOfKeys, enCharType charType)
    {

        for (int i = 1; i <= numberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(charType) << endl;
        }

    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int from, int to)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(from, to);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType charType, short wordLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(charType, wordLength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType charType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(charType);
    }

    static  void Swap(int& a, int& b)
    {
        int temp;

        temp = a;
        a = b;
        b = temp;
    }

    static  void Swap(double& a, double& b)
    {
        double temp;

        temp = a;
        a = b;
        b = temp;
    }

    static  void Swap(bool& a, bool& b)
    {
        bool temp;

        temp = a;
        a = b;
        b = temp;
    }

    static  void Swap(char& a, char& b)
    {
        char temp;

        temp = a;
        a = b;
        b = temp;
    }

    static  void Swap(string& a, string& b)
    {
        string temp;

        temp = a;
        a = b;
        b = temp;
    }

    static  void Swap(clsDate& a, clsDate& b)
    {
        clsDate::SwapDates(a, b);

    }

    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static string  Tabs(short numberOfTabs)
    {
        string t = "";

        for (int i = 1; i < numberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string  EncryptText(string text, short encryptionKey = 2)
    {

        for (int i = 0; i < text.length(); i++)
        {

            text[i] = char((int)text[i] + encryptionKey);

        }

        return text;

    }

    static string  DecryptText(string text, short encryptionKey = 2)
    {

        for (int i = 0; i < text.length(); i++)
        {

            text[i] = char((int)text[i] - encryptionKey);

        }
        return text;

    }

    static string NumberToText(int number)
    {

        if (number == 0)
        {
            return "";
        }

        if (number >= 1 && number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[number] + " ";

        }

        if (number >= 20 && number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[number / 10] + " " + NumberToText(number % 10);
        }

        if (number >= 100 && number <= 199)
        {
            return  "One Hundred " + NumberToText(number % 100);
        }

        if (number >= 200 && number <= 999)
        {
            return   NumberToText(number / 100) + "Hundred " + NumberToText(number % 100);
        }

        if (number >= 1000 && number <= 1999)
        {
            return  "One Thousand " + NumberToText(number % 1000);
        }

        if (number >= 2000 && number <= 999999)
        {
            return   NumberToText(number / 1000) + "Thousand " + NumberToText(number % 1000);
        }

        if (number >= 1000000 && number <= 1999999)
        {
            return  "One Million " + NumberToText(number % 1000000);
        }

        if (number >= 2000000 && number <= 999999999)
        {
            return   NumberToText(number / 1000000) + "Million " + NumberToText(number % 1000000);
        }

        if (number >= 1000000000 && number <= 1999999999)
        {
            return  "One Billion " + NumberToText(number % 1000000000);
        }
        else
        {
            return   NumberToText(number / 1000000000) + "Billion " + NumberToText(number % 1000000000);
        }
    }

};