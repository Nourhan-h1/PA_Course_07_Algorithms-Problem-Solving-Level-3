// Problem 35 - Print All Words in Text
//
// Splits the text on the delimiter (a space) by repeatedly finding it with
// find(), printing the word before it, and erasing the part already handled.
// Empty words caused by repeated spaces are skipped.

// problem_35_print All words in the text.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void printWords(string text)
{
    string delimiter = " ";
    short pos = 0;
    string word;

    cout << "\nYour string words are: \n\n";

    while ((pos = text.find(delimiter)) != string::npos)
    {
        word = text.substr(0, pos);
        if (word != "")
        {
            cout << word << endl;
        }

        text.erase(0, pos + delimiter.length());
    }

    if (text != "")
    {
        cout << text << endl;
    }
}

int main()
{
    string userText = readText("Please Enter a Text?\n");

    printWords(userText);
    return 0;
}

