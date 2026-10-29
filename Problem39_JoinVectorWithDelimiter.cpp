// problem_39_Join vector with separators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

short readNumber(const string& message)
{
    short number = 0;
    cout << message;
    cin >> number;
    return number;
}

string readText(const string& message)
{
    string text = "";
    cout << message;
    cin.ignore();
    getline(cin, text);
    return text;
}

vector<string> takeTheWordsFromUser(short size)
{
    vector<string> words;
    string x = "";
    for (int i = 0; i < size; i++)
    {
        cin >> x;
        words.push_back(x);
    }
    return words;
}

string joinWords(const vector<string>& words, string delimiter = " ")
{
    string text = "";
    for (const string& word : words)
    {
        text += word + delimiter;
    }

    if (!text.empty())
    {
        text = text.substr(0, text.length() - delimiter.length());
    }

    return text;
}


void printTheTextAfterJoin(const vector<string>& words, string delimiter)
{
    cout << "\nVector after join: \n";
    cout << joinWords(words, delimiter) << endl;
}

int main()
{
    short size = readNumber("Enter the number of names in your vector to join: ");

    cout << "\nEnter the words: \n";
    vector<string> words = takeTheWordsFromUser(size);

    string delimiter = readText("\nEnter your delimiter (e.g. , or - or [space]): ");

    printTheTextAfterJoin(words, delimiter);

    return 0;
}
