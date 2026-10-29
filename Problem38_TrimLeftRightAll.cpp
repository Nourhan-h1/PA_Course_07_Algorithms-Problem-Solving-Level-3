// problem_38_Trim left , right , all.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

string trimLeft(string text)
{
    for (size_t i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
        {
            return text.substr(i, text.length() - i);
        }
    }
    return "";
}

string trimRight(string text)
{
    for (int i = text.length() - 1; i >= 0; i--)
    {
        if (text[i] != ' ')
        {
            return text.substr(0, i + 1);
        }
    }
    return "";
}

string trim(string text)
{
    return trimLeft(trimRight(text));
}

int main()
{
    string userText = readText("Please Enter a Text?\n");

    cout << "\nLeft trim  = " << trimLeft(userText) << endl;
    cout << "Right trim = " << trimRight(userText) << endl;
    cout << "Trim       = " << trim(userText) << endl;

    return 0;
}
