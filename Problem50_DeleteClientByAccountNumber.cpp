// Problem 50 - Delete Client by Account Number
//
// Loads all clients from Clients.txt, finds the account number, asks for
// confirmation, marks the record with markForDelete, and then rewrites the
// file without the marked record.

// problem_50_delete client by account number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string CLIENTS_FILE_NAME = "Clients.txt";

struct ClientData {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
    bool markForDelete = false;
    ClientData() : accountBalance(0.0) {}
};

string readClientAccountNumber(string massage) {
    string accountNum = "";
    cout << massage;
    cin >> accountNum;
    return accountNum;
}

vector<string> splitString(string line, string delimiter = "#//#") {

    vector<string> vClient;

    size_t pos = 0;
    string word;

    while ((pos = line.find(delimiter)) != string::npos) {

        word = line.substr(0, pos);

        if (word != "") {

            vClient.push_back(word);

        }
        line.erase(0, pos + delimiter.length());
    }
    if (line != "") {
        vClient.push_back(line);
    }
    return vClient;
}

ClientData convertLinetoRecord(string line) {
    vector<string> vClient = splitString(line);

    ClientData client;
    if (vClient.size() >= 5) {
        client.accountNumber = vClient[0];
        client.pinCode = vClient[1];
        client.name = vClient[2];
        client.phone = vClient[3];
        client.accountBalance = stod(vClient[4]);
    }
    return client;
}

vector<ClientData> loadClientsDataFromFile() {
    vector<ClientData> vClients;

    fstream file;
    file.open(CLIENTS_FILE_NAME, ios::in);

    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            ClientData client = convertLinetoRecord(line);
            vClients.push_back(client);
        }
        file.close();
    }
    return vClients;
}

void printClientCard(const ClientData& client) {
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------\n";
    cout << "Account Number  : " << client.accountNumber << endl;
    cout << "PIN Code        : " << client.pinCode << endl;
    cout << "Name            : " << client.name << endl;
    cout << "Phone           : " << client.phone << endl;
    cout << "Account Balance : " << client.accountBalance << endl;
    cout << "-----------------------------------\n";
}

bool findClientByAccountNumber(const vector<ClientData>& vClients, const string& accountNumber, ClientData& client) {
    
    for (const ClientData& c : vClients) {
        if (c.accountNumber == accountNumber) {
            client = c;
            return true;
        }
    }
    return false;
}

bool markClientForDeleteByAccountNumber(vector<ClientData>& vClients, const string& accountNumber) {
    
    for (ClientData& c : vClients) {
        
        if (c.accountNumber == accountNumber) {
           
            c.markForDelete = true;
            return true;
        }
    }
    return false;
}

string convertRecordToLine(const ClientData& client, string delimiter = "#//#") {
    string line = "";
    line += client.accountNumber + delimiter;
    line += client.pinCode + delimiter;
    line += client.name + delimiter;
    line += client.phone + delimiter;
    line += to_string(client.accountBalance);
    return line;
}

void saveClientsDataToFile(const vector<ClientData>& vClients) {
    fstream file;
    file.open(CLIENTS_FILE_NAME, ios::out);

    string dataLine;
    if (file.is_open()) {
        for (const ClientData& client : vClients) {
            if (!client.markForDelete) {
                dataLine = convertRecordToLine(client);
                file << dataLine << endl;
            }
        }
        file.close();
    }
}

void deleteClientByAccountNumber(string& accountNumber, vector<ClientData>& vClients) {
    ClientData client;
    char deleteAccount = 'n';

    if (findClientByAccountNumber(vClients, accountNumber, client)) {

        printClientCard(client);

        cout << "\nAre you sure you want to delete this client? (Y/N): ";
        cin >> deleteAccount;

        if (toupper(deleteAccount) == 'Y') {
            markClientForDeleteByAccountNumber(vClients, accountNumber);
            saveClientsDataToFile(vClients);

            vClients = loadClientsDataFromFile();
            cout << "\n\nClient Deleted Successfully.\n";
        }
    }
    else {
        cout << "\nClient with Account Number (" << accountNumber << ") is not found!\n";
    }
}

int main() {
    vector<ClientData> vClients = loadClientsDataFromFile();

    string accountNumber = readClientAccountNumber("Please enter AccountNumber: ");
    deleteClientByAccountNumber(accountNumber, vClients);

    system("pause>0");
    return 0;
}

