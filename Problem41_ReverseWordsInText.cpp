// problem_41_print Text After reverse it is.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


string reverseWordsInText(const string& text)
{
    vector<string> words = splitWordsIntoVector(text);
    string reversedText = "";

    vector<string>::iterator iter = words.end();
    while (iter != words.begin())
    {
        --iter;
        reversedText += *iter + " ";
    }

    if (!reversedText.empty())
    {
        reversedText = reversedText.substr(0, reversedText.length() - 1);
    }

    return reversedText;
}

int main()
{
    string userText = readText("Please enter your text: \n");

    cout << "\nString after reversing words:\n";
    cout << reverseWordsInText(userText) << endl;

    return 0;
}

