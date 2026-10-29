// problem_44_remove punctuations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string readText(const string& message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

string removePunctuations(const string& text)
{
    string result = "";
    for (char c : text)
	{
		if (!ispunct(c))
		{
			result += c;
		}
	}
	return result;
}

int main()
{
    string userText = readText("Please enter your text: ");
	cout << "Original text: " << userText << endl;
	cout << "Text without punctuations: " << removePunctuations(userText) << endl;
}
