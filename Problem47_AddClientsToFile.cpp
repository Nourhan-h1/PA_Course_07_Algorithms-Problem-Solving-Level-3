// Problem 47 - Add Clients to File
//
// Reads clients from the user and appends each one as a line (same format as
// Problem 45) to Clients.txt, which is created in the working directory if it
// does not exist. Uses system("cls"), so it is meant for the Windows console.

// problem_47_enter clients and save them to file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string CLIENTS_FILE_NAME = "Clients.txt";

struct stClientData {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
    stClientData() : accountBalance(0.0) {}
};

stClientData readNewClient() {
    stClientData client;

    // Usage of std::ws will extract allthe whitespace character
    cout << "Enter Account Number? ";
    getline(cin >> ws, client.accountNumber);

    cout << "Enter PinCode? ";
    getline(cin, client.pinCode);

    cout << "Enter Name? ";
    getline(cin, client.name);

    cout << "Enter Phone? ";
    getline(cin, client.phone);

    cout << "Enter AccountBalance? ";
    cin >> client.accountBalance;

    return client;
}

string convertRecordToLine(const stClientData& client, string delimiter = "#//#") {
    string textRecord = "";
    textRecord += client.accountNumber + delimiter;
    textRecord += client.pinCode + delimiter;
    textRecord += client.name + delimiter;
    textRecord += client.phone + delimiter;
    textRecord += to_string(client.accountBalance);
    return textRecord;
}

void addDataLineToFile(const string& fileName, const string& dataLine) {
    fstream file;
    file.open(fileName, ios::out | ios::app);

    if (file.is_open()) {
        file << dataLine << endl;
        file.close();
    }
}

void addNewClient() {
    stClientData client = readNewClient();
    addDataLineToFile(CLIENTS_FILE_NAME, convertRecordToLine(client));
}

void addClients() {
    char addMore = 'Y';
    do {
        system("cls");
        cout << "Adding New Client:\n\n";

        addNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> addMore;
    } while (toupper(addMore) == 'Y');
}

int main() {
    addClients();
    return 0;
}
