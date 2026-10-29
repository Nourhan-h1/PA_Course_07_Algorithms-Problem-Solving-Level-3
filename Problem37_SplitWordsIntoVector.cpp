// problem_37_split Each Word in the Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

vector<string> splitWords(string text, string delimiter = " ")
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

void printWords(const vector<string>& words)
{
    cout << "\nYour string words are: \n\n";
    for (const string& word : words)
    {
        cout << word << endl;
    }
}

int main()
{
    string userText = readText("Please Enter a Text?\n");
    vector<string> words = splitWords(userText);

    cout << "\nTokens = " << words.size() << endl;

    printWords(words);

    return 0;
}
