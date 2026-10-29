// problem_34_print All Vowels in the text.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>

using namespace std;

string readText(const string& message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

bool isVowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o');
}

void printVowels(const string& text)
{
    for (char ch : text)
    {
        if (isVowel(ch))
            cout << ch << "    ";
    }
    cout << endl;
}

int main()
{
    string userText = readText("Please Enter a Text?\n");

    cout << "\nThe vowels in the text are: ";
    printVowels(userText);

    return 0;
}
