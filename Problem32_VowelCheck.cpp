// problem_32_check isVowels or not.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

char readChar(const string& message)
{
    char character;
    cout << message;
    cin >> character;
    return character;
}

bool isVowel(char ch)
{
	ch = tolower(ch); // Convert to lowercase for all comparisons
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o');
}

void printVowelCheckResult(char ch)
{
	if (isVowel(ch))
		cout << "\nThe character '" << ch << "' is a vowel." << endl;
	else
		cout << "\nThe character '" << ch << "' is not a vowel." << endl;
}

int main()
{
    char userChar = readChar("Please Enter a Character?\n");
	printVowelCheckResult(userChar);
    return 0;
}
