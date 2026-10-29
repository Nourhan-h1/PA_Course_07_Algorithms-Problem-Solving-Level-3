// Problem 46 - Line to Client Record
//
// The reverse of Problem 45: splits a line on the "#//#" delimiter and fills a
// client record from the pieces (the balance is converted with stod).
// The line is hard-coded in main().
//
// Example Output (extracted record):
//   Account Number  : A150
//   PIN Code        : 1234
//   Name            : Nourhan Hany
//   Phone           : 079999
//   Account Balance : 5270

// problem_46_convert line data to record.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClientData
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance = 0.0;
};

vector<string> splitWordsIntoVector(string text, const string& delimiter)
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

stClientData ConvertLinetoRecord(string line, const string& delimiter = "#//#")
{
    vector<string> vClientData = splitWordsIntoVector(line, delimiter);
    stClientData client;

    client.accountNumber = vClientData[0];
    client.pinCode = vClientData[1];
    client.name = vClientData[2];
    client.phone = vClientData[3];
    client.accountBalance = stod(vClientData[4]);

    return client;
}

void printClientRecord(stClientData client)
{
    cout << "The following is the extracted client record\n\n";
    cout << "Account Number  : " << client.accountNumber << endl;
    cout << "PIN Code        : " << client.pinCode << endl;
    cout << "Name            : " << client.name << endl;
    cout << "Phone           : " << client.phone << endl;
    cout << "Account Balance : " << client.accountBalance << endl;
}

int main()
{
    string stLine = "A150#//#1234#//#Nourhan Hany#//#079999#//#5270.000000";
    cout << "\nLine Record is:\n";
    cout << stLine;
    stClientData client = ConvertLinetoRecord(stLine);
    printClientRecord(client);
    return 0;
}
