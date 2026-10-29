// Problem 23 - First Letter of Each Word
//
// Prints the first letter of every word, one per line. A letter is the first
// letter of a word when the previous character was a space (or when it is the
// first character of the text).

// problem_23_First Letter Extractor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string readText(string message)
{
	string text = "";
	cout << message;
	getline(cin, text);
	return text;
}

void printFirstLetterOfEachWord(string text)
{
	bool isFirstLetter = true;

	for (int i = 0; i < text.length(); i++)
	{
		if(text[i] != ' ' && isFirstLetter)
		{
			cout << text[i] << endl;
		}
		isFirstLetter = (text[i] == ' ');
	}
}

int main()
{
	string userText = readText("Please Enter Your String?\n\n");

	cout << "The First Letter of Each Word in the String is:\n";
	printFirstLetterOfEachWord(userText);

    return 0;
}
