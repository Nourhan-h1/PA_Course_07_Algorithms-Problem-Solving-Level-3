// problem_40_String-Join-Overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

// Overload 1: Joins words from a vector of strings
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

// Overload 2: Joins words from a traditional array of strings
string joinWords(const string array[], int size, string delimiter = " ")
{
    string text = "";
    for (int i = 0; i < size; i++)
    {
        text += array[i] + delimiter;
    }

    if (!text.empty())
    {
        text = text.substr(0, text.length() - delimiter.length());
    }

    return text;
}

int main()
{
    short size = readNumber("Enter the number of names to join: ");
    cout << "\nEnter the words: \n";
    vector<string> vWords = takeTheWordsFromUser(size);

    string delimiter = readText("\nEnter your delimiter (e.g. , or - or [space]): ");

    // Test Overload 1: Using Vector
    cout << "\nVector after join: \n";
    cout << joinWords(vWords, delimiter) << endl;

    // Test Overload 2: Copying data to a fixed-size array to safely demonstrate the array overload
    string arrWords[100];
    for (int i = 0; i < size; i++)
    {
        arrWords[i] = vWords[i];
    }

    cout << "\nArray after join: \n";
    cout << joinWords(arrWords, size, delimiter) << endl;

    return 0;
}
