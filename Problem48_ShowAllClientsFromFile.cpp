// problem_48_show all clients from file.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void printClientRecord(const sClientData& client)
{
    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(10) << left << client.pinCode;
    cout << "| " << setw(35) << left << client.name;
    cout << "| " << setw(15) << left << client.phone;
    cout << "| " << setw(12) << left << client.accountBalance;
}

void printAllClientsData(const vector<sClientData>& clients)
{
    cout << "\n\t\t\t\tClient List (" << clients.size() << ") Client(s)";
    cout << "\n__________________________________________________________________________________________________\n";
    cout << "| " << setw(15) << left << "Account Number";
    cout << "| " << setw(10) << left << "Pin Code";
    cout << "| " << setw(35) << left << "Client Name";
    cout << "| " << setw(15) << left << "Phone";
    cout << "| " << setw(12) << left << "Balance";
    cout << "\n__________________________________________________________________________________________________\n";

    for (const sClientData& client : clients)
    {
        printClientRecord(client);
        cout << endl;
    }
    cout << "__________________________________________________________________________________________________\n";
}

int main() {
    vector<sClientData> vClients = loadClientsDataFromFile(CLIENTS_FILE_NAME);
    printAllClientsData(vClients);

    system("pause>0");
    return 0;
}
