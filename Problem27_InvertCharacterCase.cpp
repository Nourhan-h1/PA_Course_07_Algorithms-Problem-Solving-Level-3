// problem_27_invertCase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

char readChar(string message)
{
    char ch;
    cout << message;
    cin >> ch;
    return ch;
}

char invertCase(char ch)
{ 
    return (isupper(ch) ? tolower(ch) : toupper(ch));
}

int main()
{
    char userChar = readChar("Please Enter a Character?\n");

    cout << "\nInverted Case:\n";
    cout << invertCase(userChar) << endl;

    return 0;
}
