// problem_28_invertAllLetter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string readText(string message)
{
    string text;
    cout << message;
    getline(cin, text);
    return text;
}

string invertAllCases(string text)
{
	for (size_t i = 0; i < text.size(); i++)
	{
		text[i] = (isupper(text[i]) ? tolower(text[i]) : toupper(text[i]));
	}
	return text;
}

int main()
{
    string userText = readText("Please Enter a Text?\n");

    cout << "\nString after Inverting All Letters Case:\n";
    cout << invertAllCases(userText) << endl;

    return 0;
}
