// problem_29_count Small and Capital Letter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string readText(const string& message)
{
    string text;
    cout << message;
    getline(cin, text);
    return text;
}

//enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
//short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
//{
//    if (WhatToCount == enWhatToCount::All)
//        return S1.length();
//
//    else if (WhatToCount == enWhatToCount::SmallLetters)
//    {
//        int count = 0;
//        for (char ch : S1)
//        {
//            if (islower(ch))
//                count++;
//        }
//        return count;
//    }
//
//	else if (WhatToCount == enWhatToCount::CapitalLetters)
//	{
//		int count = 0;
//		for (char ch : S1)
//		{
//			if (isupper(ch))
//				count++;
//		}
//		return count;
//	}
//}

int countStringLength(const string& text)
{
	return text.length();
}

int countSmallLetters(const string& text)
{
    int count = 0;
    for (char ch : text)
    {
        if (islower(ch))
            count++;
    }
    return count;
}

int countCapitalLetters(const string& text)
{
    int count = 0;
    for (char ch : text)
    {
        if (isupper(ch))
            count++;
    }
    return count;
}

int main()
{
    string userText = readText("Please Enter a Text?\n");

    //cout << "\nString Length: " << CountLetters(userText) << endl;
    //cout << "Number of Small Letters: " << CountLetters(userText, enWhatToCount::SmallLetters) << endl;
    //cout << "Number of Capital Letters: " << CountLetters(userText, enWhatToCount::CapitalLetters) << endl;

	cout << "\nString Length: " << countStringLength(userText) << endl;
	cout << "Number of Small Letters: " << countSmallLetters(userText) << endl;
	cout << "Number of Capital Letters: " << countCapitalLetters(userText) << endl;
    

    return 0;
}
