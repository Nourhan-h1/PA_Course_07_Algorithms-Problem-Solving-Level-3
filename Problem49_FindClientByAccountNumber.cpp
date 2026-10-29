// problem_49_find client by accountNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string CLIENTS_FILE_NAME = "Clients.txt";

struct sClientData {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance = 0.0;
};

string readClientAccountNumber(const string& message)
{
    string text = "";
    cout << message;
    getline(cin, text);
    return text;
}

vector<string> splitDataIntoVector(string text, const string& delimiter)
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

sClientData convertLinetoRecord(string line, const string& delimiter = "#//#")
{
    vector<string> vClientData = splitDataIntoVector(line, delimiter);
    sClientData client;

    if (vClientData.size() >= 5)
    {
        client.accountNumber = vClientData[0];
        client.pinCode = vClientData[1];
        client.name = vClientData[2];
        client.phone = vClientData[3];
        client.accountBalance = stod(vClientData[4]);
    }

    return client;
}

vector<sClientData> loadClientsDataFromFile(string fileName)
{
    vector<sClientData> clientsData;
    fstream file;
    file.open(fileName, ios::in);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            sClientData client = convertLinetoRecord(line);
            clientsData.push_back(client);
        }
        file.close();
    }
    return clientsData;
}

void printClientCard(const sClientData& client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------\n";
    cout << "Account Number  : " << client.accountNumber << endl;
    cout << "PIN Code        : " << client.pinCode << endl;
    cout << "Name            : " << client.name << endl;
    cout << "Phone           : " << client.phone << endl;
    cout << "Account Balance : " << client.accountBalance << endl;
    cout << "-----------------------------------\n";
}

bool findClientByAccountNumber(const string& accountNumber, sClientData& client)
{
    vector<sClientData> vClients = loadClientsDataFromFile(CLIENTS_FILE_NAME);
    for (sClientData& c : vClients)
    {
        if (c.accountNumber == accountNumber)
        {
            client = c; 
            return true;
        }
    }
    return false;
}

int main() {
    sClientData client;
    string accountNumber = readClientAccountNumber("Enter your Account Number: ");

    if (findClientByAccountNumber(accountNumber, client))
    {
        printClientCard(client);
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!\n";
    }

    system("pause>0");
    return 0;
}
