// problem_31_count letter in the text (match or not).cpp : This file contains the 'main' function. Program execution begins and ends there.
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

char invertLetterCase(char ch)
{
    return  (isupper(ch) ? tolower(ch) : toupper(ch));
}

int countCharacterInText(const string& text, char character , bool matchCase = true)
{
    int counter = 0;
    for (char ch : text)
    {
        if (matchCase)
        {
			if (ch == character)
				counter++;
        }
        else 
        {
            if (tolower(ch) == tolower(character))
                counter++;
        }
    }
    return counter;
}

int main()
{
    string userText = readText("Please Enter a Text?\n");
    char userChar = readChar("\nPlease Enter a Character to Count?\n");
  
	int count = countCharacterInText(userText, userChar);
	int countIgnoreCase = countCharacterInText(userText, userChar , false);

    cout << "\nLetter '" << userChar << "' Count = " << count << endl;
    cout << "\nLetter '" << userChar << "' or '" << invertLetterCase(userChar) << "' Count = " << countIgnoreCase << endl;
    return 0;
}