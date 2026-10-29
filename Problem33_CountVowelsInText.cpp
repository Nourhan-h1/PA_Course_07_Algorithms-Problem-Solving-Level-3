// problem_33_count Vowels letters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string readText(const string& message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

bool isVowel(char ch)
{
    ch = tolower(ch); // Convert to lowercase for all comparisons
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'u' || ch == 'o');
}


int countVowelsInText(const string& text)
{
    int count = 0;
    for (char ch : text)
    {
        if (isVowel(ch))
            count++;
    }
    return count;
}

int main()
{
    string userText = readText("Please Enter a Text?\n");
    
	cout << "\nThe number of vowels in the text is: " << countVowelsInText(userText) << endl;
    return 0;
}
