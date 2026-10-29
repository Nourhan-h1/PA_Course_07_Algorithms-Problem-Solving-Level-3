// problem_24_lowercaseTheFirstLetter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<cctype>
#include <string>

using namespace std;

string readText(string message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

string lowerFirstLetterOfEachWord(string text)
{
    bool isFirstLetter = true;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ' && isFirstLetter)
        {
            text[i] = tolower(text[i]);
        }
        isFirstLetter = (text[i] == ' ');
    }

    return text;
}

int main()
{
    string userText = readText("Please Enter Your String?\n\n");

    cout << "\nString after conversion:\n";
    string convertedText = lowerFirstLetterOfEachWord(userText);
    cout << convertedText << endl;

    return 0;
}
