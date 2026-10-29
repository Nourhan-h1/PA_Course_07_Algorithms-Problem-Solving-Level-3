// Problem 45 - Client Record to Line
//
// Reads one client's data and converts it into a single line that can be saved
// to a text file. The fields are joined with the "#//#" delimiter in this order:
// AccountNumber, PinCode, Name, Phone, AccountBalance.
// The same line format is used in the following problems and in both projects.

// problem_45_convert data in one line.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;

struct stClientData
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance = 0.0;
};

stClientData readNewClient()
{
    stClientData client;

    cout << "Enter your Account Number? ";
    getline(cin, client.accountNumber);

    cout << "Enter your PinCode? ";
    getline(cin, client.pinCode);

    cout << "Enter your Name? ";
    getline(cin, client.name);

    cout << "Enter your Phone? ";
    getline(cin, client.phone);

    cout << "Enter your Account Balance? ";
    cin >> client.accountBalance;

    return client;
}

string convertRecordToLine(stClientData client, string delimiter = "#//#")
{
    string textRecord = "";
    textRecord += client.accountNumber + delimiter;
    textRecord += client.pinCode + delimiter;
    textRecord += client.name + delimiter;
    textRecord += client.phone + delimiter;
    textRecord += to_string(client.accountBalance);
    return textRecord;
}

int main()
{
    cout << "\nPlease Enter Client Data: \n\n";
    stClientData clientData;
    clientData = readNewClient();

    cout << "\n\nClient Record for Saving is: \n";
    cout << convertRecordToLine(clientData) << endl;

    return 0;
}

