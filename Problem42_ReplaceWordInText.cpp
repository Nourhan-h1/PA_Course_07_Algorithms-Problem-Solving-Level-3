// problem_42_replace worlds in the strinh.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string readText(const string& message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

string readWord(const string& message)
{
    string word = "";
    cout << message;
    cin >> word;
    return word;
}

vector<string> splitWordsIntoVector(string text)
{
    size_t pos = 0;
    string word;
    vector<string> words;
    string delimiter = " ";

    while ((pos = text.find(delimiter)) != string::npos)
    {
        word = text.substr(0, pos);
        if (word != "")
        {
            words.push_back(word);
        }
        text.erase(0, pos + delimiter.length());
    }

    if (text != "")
    {
        words.push_back(text);
    }

    return words;
}

string replaceWordInText(const string& text, const string& oldWord, const string& newWord)
{
    vector<string> words = splitWordsIntoVector(text);
    string replacedText = "";

    for (const string& word : words)
    {
        if (word == oldWord)
        {
            replacedText += newWord + " ";
        }
        else
        {
            replacedText += word + " ";
        }
    }

    if (!replacedText.empty())
    {
        replacedText = replacedText.substr(0, replacedText.length() - 1);
    }

    return replacedText;
}

int main()
{
    string userText = readText("Please enter your text: ");
    string wordToReplace = readWord("\nPlease enter the word to replace: ");
    string replacementWord = readWord("Please enter the replacement word: ");

    cout << "\nOriginal String:\n" << userText << "\n";
    cout << "\nString After Replace:\n" << replaceWordInText(userText, wordToReplace, replacementWord) << "\n";

    return 0;
}
