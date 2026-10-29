// problem_43_replace words in match case.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

string readWord(const string& message)
{
    string word = "";
    cout << message;
    cin >> word;
    return word;
}

vector<string> splitString(string text, const string& delimiter)
{
    size_t pos = 0;
    string word;
    vector<string> words;

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

string joinString(const vector<string>& words, const string& delimiter)
{
    string text = "";
    for (const string& s : words)
    {
        text += s + delimiter;
    }
    return text.substr(0, text.length() - delimiter.length());
}

string lowerAllString(const string& text)
{
    string lowerText = text;
    for (char& ch : lowerText)
    {
        ch = tolower(ch);
    }
    return lowerText;
}

string replaceWordInText(const string& text, const string& oldWord, const string& newWord, bool matchCase = false)
{
    vector<string> words = splitString(text, " ");
    string lowerOldWord = (matchCase ? "" : lowerAllString(oldWord));

    for (string& word : words) 
    {
        if (matchCase)
        {
            if (word == oldWord)
            {
                word = newWord;
            }
        }
        else
        {
            if (lowerAllString(word) == lowerOldWord)
            {
                word = newWord;
            }
        }
    }
    return joinString(words, " ");
}

int main()
{
    string userText = readText("Please enter your text: ");
    string wordToReplace = readWord("\nPlease enter the word to replace: ");
    string replacementWord = readWord("Please enter the replacement word: ");

    cout << "\nOriginal String:\n" << userText << "\n";
    cout << "\n\nReplace with match case:\n" << replaceWordInText(userText, wordToReplace, replacementWord, true);
    cout << "\n\nReplace with dont match case:\n" << replaceWordInText(userText, wordToReplace, replacementWord) << endl;
    return 0;
}
