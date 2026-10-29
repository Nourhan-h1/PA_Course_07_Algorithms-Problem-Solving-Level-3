// problem_36_count Each Word in the text.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int countWords(string text)
{
    string delimiter = " ";
    size_t pos = 0;
    string word;
    int counter = 0;

    while ((pos = text.find(delimiter)) != string::npos)
    {
        word = text.substr(0, pos);
        if (word != "")
        {
            counter++;
        }

        text.erase(0, pos + delimiter.length());
    }

    if (text != "")
    {
        counter++;
    }

    return counter;
}

int main()
{
    string userText = readText("Please Enter a Text?\n");

    int wordCount = countWords(userText);
    cout << "\nNumber of words in the text: " << wordCount << endl;

    return 0;
}
