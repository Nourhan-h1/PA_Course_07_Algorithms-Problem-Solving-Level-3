// problem_30_count Character in the text.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string readText(const string& message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

char readChar(const string& message)
{
    char character;
    cout << message;
    cin >> character;
    return character;
}

int countCharacterInText(const string& text, char character)
{
    int count = 0;
    for (char ch : text)
    {
        if (ch == character)
            count++;
    }
    return count;
}


void printCharacterCount(const string& text, char character)
{
	int count = countCharacterInText(text, character);
	cout << "\nThe character '" << character << "' appears " << count << " times in the text." << endl;
}

int main()
{
	string userText = readText("Please Enter a Text?\n");
	char userChar = readChar("\nPlease Enter a Character to Count?\n");
    printCharacterCount(userText, userChar); 
    return 0;
}
