// problem_26_upperAndLowerAllLetter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string readText(string message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

string convertToUpper(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = toupper(text[i]);
	}
	return text;
}

string convertToLower(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = tolower(text[i]);
	}
	return text;
}

int main()
{
    string userText = readText("Please Enter Your String?\n\n");


	cout << "\nString after upper conversion:\n";
	cout << convertToUpper(userText) << endl;

	cout << "\nString after lower conversion:\n";
	cout << convertToLower(userText) << endl;
    return 0;
}
