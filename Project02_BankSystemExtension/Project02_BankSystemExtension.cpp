// Project 02 - Bank System Extension
//
// Extends Project 01 with a Transaction menu. Main menu:
//   [1] Show Client List   [2] Add New Client   [3] Delete Client
//   [4] Update Client Info [5] Find Client      [6] Transaction Menu  [7] Exit
//
// Transaction menu:
//   [1] Deposit   [2] Withdraw   [3] Show Total Balances   [4] Main Menu
//
// Deposits and withdrawals ask for an existing account number and a
// confirmation; a withdrawal larger than the balance is refused.
// Clients are stored in Clients.txt in the same "#//#" format as Project 01
// (empty records are skipped when the file is loaded).
//
// Notes: uses system("cls") and system("pause>0"), so it targets the Windows
// console. The Visual Studio project is configured for C++20.

// project_2_Bank Extension.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string CLIENTS_FILE_NAME = "Clients.txt"; 

enum enMainMenuOptions {
    ShowClientList = 1,
    AddNewClient = 2,
    DeleteClient = 3,
    UpdateClientInfo = 4,
    FindClient = 5,
	TransactionMenu = 6,
    Exit = 7
};

enum enTransactionMenuOptions {
	Deposit = 1,
	Withdraw = 2,
	ShowTotalBalances = 3,
	MainMenu = 4
};

struct ClientData {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
    bool markForDelete = false;
    ClientData() : accountBalance(0.0) {}
};

void startApplication();
void startTransactionMenu();
void showMainMenu();
void showTransactionMenu();
void performMainMenuOptions(enMainMenuOptions mainMenuOption);
void performTransactionMenuOptions(enTransactionMenuOptions transactionMenuOption);

int readMainMenuOption() {
    int option = 0;
    cout << "Please choose what do you want to do? [1 to 7]: ";
    cin >> option;
    return option;
}

int readTransactionMenuOption() {
    int option = 0;
    cout << "Please choose what do you want to do? [1 to 4]: ";
    cin >> option;
    return option;
}

string readClientAccountNumber(string message) {
    string accountNum = "";
    cout << message;
	getline(cin >> ws, accountNum);
    return accountNum;
}

void goBackToMainMenu() {
    cout << "\n\nPress any key to go back to Main Menu...";
    system("pause>0");

    startApplication();
}

void goBackToTransactionMenu() {
	cout << "\n\nPress any key to go back to Transaction Menu...";
	system("pause>0");

	startTransactionMenu();
}

double countAccountsBalance(const vector<ClientData>& clients) {
	double totalBalance = 0.0;
	for (const ClientData& client : clients) {
		totalBalance += client.accountBalance;
	}
	return totalBalance;
}

vector<string> splitString(string line, string delimiter = "#//#") {
    size_t pos = 0;
    string word;
    vector<string> clientData;

    while ((pos = line.find(delimiter)) != string::npos) {
        word = line.substr(0, pos);
        if (word != "") {
            clientData.push_back(word);
        }
        line.erase(0, pos + delimiter.length());
    }

    if (line != "") {
        clientData.push_back(line);
    }
    return clientData;
}

ClientData convertLinetoRecord(string line) {
    vector<string> vClientData = splitString(line);
    ClientData client;

    if (vClientData.size() >= 5) {
        client.accountNumber = vClientData[0];
        client.pinCode = vClientData[1];
        client.name = vClientData[2];
        client.phone = vClientData[3];
        client.accountBalance = stod(vClientData[4]);
    }
    return client;
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

vector<ClientData> loadClientsDataFromFile() {
    vector<ClientData> clientsData;
    fstream file;
    file.open(CLIENTS_FILE_NAME, ios::in);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            ClientData client = convertLinetoRecord(line);

            if (client.accountNumber != "") {
                clientsData.push_back(client);
            }
        }
        file.close();
    }
    return clientsData;
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

void addDataLineToFile(string dataLine) {
    fstream file;
    file.open(CLIENTS_FILE_NAME, ios::out | ios::app);

    if (file.is_open()) {
        file << dataLine << endl;
        file.close();
    }
}

bool findClientByAccountNumber(string accountNumber, ClientData& client) {
    vector<ClientData> vClients = loadClientsDataFromFile();

    for (const ClientData& c : vClients) {
        if (c.accountNumber == accountNumber) {

            client = c;
            return true;
        }
    }
    return false;
}

bool markClientForDeleteByAccountNumber(vector<ClientData>& vClients, string accountNumber) {

    for (ClientData& c : vClients) {
        if (c.accountNumber == accountNumber) {

            c.markForDelete = true;
            return true;
        }
    }

    return false;
}

void showScreenHeader(string title) {
    cout << "-----------------------------------\n";
    cout << "\t" << title << "\n";
    cout << "===================================\n\n";
}

void printClientRecordRow(const ClientData& client) {
    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(10) << left << client.pinCode;
    cout << "| " << setw(35) << left << client.name;
    cout << "| " << setw(15) << left << client.phone;
    cout << "| " << setw(12) << left << client.accountBalance;
}

void printClientRecordBalanceRow(const ClientData& client) {
    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(35) << left << client.name;
    cout << "| " << setw(12) << left << client.accountBalance;
}

void printAllClientsTable(const vector<ClientData>& clients) {
    cout << "\n\t\t\t\tClient List (" << clients.size() << ") Client(s)";
    cout << "\n__________________________________________________________________________________________________\n";
    cout << "| " << setw(15) << left << "Account Number";
    cout << "| " << setw(10) << left << "Pin Code";
    cout << "| " << setw(35) << left << "Client Name";
    cout << "| " << setw(15) << left << "Phone";
    cout << "| " << setw(12) << left << "Balance";
    cout << "\n__________________________________________________________________________________________________\n";
    
    if (clients.empty()) {
        cout << "\n\t\t\t\tNo Clients Available In the System!\n";
    }
    else {
        for (const ClientData& client : clients) {
            printClientRecordRow(client);
            cout << endl;
        }
    }
    cout << "__________________________________________________________________________________________________\n";
}


void printAllClientsBalanceTable(const vector<ClientData>& clients) {
    cout << "\n\t\t\t\t Balances List (" << clients.size() << ") Client(s)";
    cout << "\n__________________________________________________________________________________________________\n";
    cout << "| " << setw(15) << left << "Account Number";
    cout << "| " << setw(35) << left << "Client Name";
    cout << "| " << setw(12) << left << "Balance";
    cout << "\n__________________________________________________________________________________________________\n";

    if (clients.empty()) {
        cout << "\n\t\t\t\tNo Clients Available In the System!\n";
    }
    else {
        for (const ClientData& client : clients) {
            printClientRecordBalanceRow(client);
            cout << endl;
        }
    }
    cout << "__________________________________________________________________________________________________\n";
}

void printClientCard(const ClientData& client) {
    cout << "\nThe following are the client details:\n";

    cout << "---------------------------------------------\n";
    cout << left << setw(18) << "Account Number" << ": " << client.accountNumber << endl;
    cout << left << setw(18) << "PIN Code" << ": " << client.pinCode << endl;
    cout << left << setw(18) << "Name" << ": " << client.name << endl;
    cout << left << setw(18) << "Phone" << ": " << client.phone << endl;
    cout << left << setw(18) << "Account Balance" << ": " << client.accountBalance << endl;
    cout << "---------------------------------------------\n";
}

ClientData readNewClient() {
    ClientData client;
    cout << "\nAdding New Client: \n\n";

    cout << left << setw(25) << "Enter Account Number" << ": ";
    getline(cin >> ws, client.accountNumber);

    ClientData tempClient;
    while (findClientByAccountNumber(client.accountNumber, tempClient)) {
        cout << "\nClient with Account Number [" << client.accountNumber << "] already exists, Enter another Account Number: ";

        getline(cin >> ws, client.accountNumber);
    }

    cout << left << setw(25) << "Enter PIN Code" << ": ";
    getline(cin, client.pinCode);

    cout << left << setw(25) << "Enter Name" << ": ";
    getline(cin, client.name);

    cout << left << setw(25) << "Enter Phone" << ": ";
    getline(cin, client.phone);

    cout << left << setw(25) << "Enter Account Balance" << ": ";
    cin >> client.accountBalance;

    return client;
}

ClientData changeClientData(string accountNumber) {
    ClientData client;
    client.accountNumber = accountNumber;

    cout << left << setw(27) << "\n\nEnter new PIN Code" << ": ";
    getline(cin >> ws, client.pinCode);

    cout << left << setw(27) << "Enter new Name" << ": ";
    cin >> ws;
    getline(cin, client.name);

    cout << left << setw(27) << "Enter new Phone" << ": ";
    getline(cin, client.phone);

    cout << left << setw(27) << "Enter new Account Balance" << ": ";
    cin >> client.accountBalance;

    return client;
}

void addNewClient() {
    ClientData client = readNewClient();
    string dataLine = convertRecordToLine(client);

    addDataLineToFile(dataLine);
}

void addClients() {
    char addMore = 'Y';

    do {
        system("cls");

        showScreenHeader("Add New Client Screen");
        addNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> addMore;

    } while (toupper(addMore) == 'Y');
}

void deleteClientByAccountNumber(string& accountNumber, vector<ClientData>& vClients) {
    ClientData client;
    char deleteAccount = 'n';

    if (findClientByAccountNumber(accountNumber, client)) {
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

void deleteClient() {
    vector<ClientData> clients = loadClientsDataFromFile();

    showScreenHeader("Delete Client Screen");
    string accountNumber = readClientAccountNumber("Enter your Account Number: ");

    deleteClientByAccountNumber(accountNumber, clients);
}

void updateClientByAccountNumber(string& accountNumber, vector<ClientData>& vClients) {

    ClientData client;
    char updateAccount = 'n';

    if (findClientByAccountNumber(accountNumber, client)) {
        printClientCard(client);

        cout << "\nAre you sure you want to update this client? (Y/N): ";
        cin >> updateAccount;

        if (toupper(updateAccount) == 'Y') {

            for (ClientData& c : vClients) {

                if (c.accountNumber == accountNumber) {

                    c = changeClientData(accountNumber);
                    break;
                }
            }

            saveClientsDataToFile(vClients);
            vClients = loadClientsDataFromFile();
            cout << "\n\nClient Updated Successfully.\n";

        }
    }
    else {
        cout << "\nClient with Account Number (" << accountNumber << ") is not found!\n";
    }
}

void updateClient() {
    vector<ClientData> clients = loadClientsDataFromFile();

    showScreenHeader("Update Client Screen");
    string accountNumber = readClientAccountNumber("Enter your Account Number: ");

    updateClientByAccountNumber(accountNumber, clients);
}

void findClient() {
    showScreenHeader("Find Client Screen");

    string accountNumber = readClientAccountNumber("Enter your Account Number: ");
    ClientData client;

    if (findClientByAccountNumber(accountNumber, client)) {
        printClientCard(client);
    }
    else {
        cout << "\nClient with Account Number (" << accountNumber << ") is not found!\n";
    }

}

void showEndScreen() {
    cout << "===========================================================\n";
    cout << "\t\tThank you for using our app\n";
    cout << "===========================================================\n\n";
}

string readExistingAccountNumber() {
    string accountNumber = readClientAccountNumber("Enter your Account Number: ");
    ClientData client;

    while (!findClientByAccountNumber(accountNumber, client)) {
        cout << "\nClient with Account Number (" << accountNumber << ") is not found!\n";
        cout << "Please enter a valid Account Number: ";
        getline(cin >> ws, accountNumber);
    }
    
	return accountNumber;
}

bool updateAccountBalance(string& accountNumber, double amount, vector<ClientData>& vClients) {
    for (ClientData& client : vClients) {
        if (client.accountNumber == accountNumber) {
            if (amount == 0) {
                return false;
            }
            if (client.accountBalance + amount < 0) {
                return false;
            }
            client.accountBalance += amount;
            return true;
        }
    }
    return false;
}

void performDeposit(string& accountNumber, double depositAmount, vector<ClientData>& clients) {
    if (depositAmount <= 0) {
        cout << "\nAmount must be greater than zero.\n";
        return;
    }

    if (updateAccountBalance(accountNumber, depositAmount, clients)) {
        saveClientsDataToFile(clients);
        cout << "\n\nDeposit operation completed successfully.\n";
    }
    else {
        cout << "\nDeposit operation failed.\n";
    }
}

void performWithdraw(string& accountNumber, double withdrawAmount, vector<ClientData>& clients) {
    if (withdrawAmount <= 0) {
        cout << "\nAmount must be greater than zero.\n";
        return;
    }

    if (updateAccountBalance(accountNumber, -withdrawAmount, clients)) {
        saveClientsDataToFile(clients);
        cout << "\n\nWithdraw operation completed successfully.\n";
    }
    else {
        cout << "\nWithdraw operation failed. Insufficient Balance!\n";
    }
}


void showDepositScreen() {
    system("cls");
    showScreenHeader("Deposit Screen");

    vector<ClientData> clients = loadClientsDataFromFile();

    string accountNumber = readExistingAccountNumber();
    
    ClientData client;
    findClientByAccountNumber(accountNumber, client); 
    printClientCard(client);

    double depositAmount = 0.0;
    cout << "\n\nEnter the amount you want to deposit: ";
    cin >> depositAmount;

    char checkToUpdate = 'n';
    cout << "\nAre you sure you want to deposit to this client? (Y/N): ";
    cin >> checkToUpdate;

    if (toupper(checkToUpdate) == 'Y') {
        performDeposit(accountNumber, depositAmount, clients);
    }
    else {
        cout << "\nDeposit operation canceled.\n";
    }
}

void showTotalBalancesScreen() {
    system("cls");
	vector<ClientData> clients = loadClientsDataFromFile();
	printAllClientsBalanceTable(clients);
    double totalBalance = countAccountsBalance(clients);
    cout << "\n\t\t\t\tTotal Balances: " << totalBalance << endl;
}

void showWithdrawScreen() {
    system("cls");
    showScreenHeader("Withdraw Screen");

    vector<ClientData> clients = loadClientsDataFromFile();

    string accountNumber = readExistingAccountNumber();

    ClientData client;
    findClientByAccountNumber(accountNumber, client);
    printClientCard(client);

    double withdrawAmount = 0.0;
    cout << "\n\nEnter the amount you want to withdraw: ";
    cin >> withdrawAmount   ;

    char checkToUpdate = 'n';
    cout << "\nAre you sure you want to withdraw from this client? (Y/N): ";
    cin >> checkToUpdate;

    if (toupper(checkToUpdate) == 'Y') {
        performWithdraw(accountNumber, withdrawAmount, clients);
    }
    else {
        cout << "\nWithdraw operation canceled.\n";
    }
}


void startTransactionMenu() {
    showTransactionMenu();
    int choice = readTransactionMenuOption();
    enTransactionMenuOptions transactionMenuOption = (enTransactionMenuOptions)choice;
    performTransactionMenuOptions(transactionMenuOption);
}

void startApplication() {
    showMainMenu();

    int choice = readMainMenuOption();
    enMainMenuOptions mainMenuOption = (enMainMenuOptions)choice;

    performMainMenuOptions(mainMenuOption);
}


void performTransactionMenuOptions(enTransactionMenuOptions transactionMenuOption) {
   
    switch (transactionMenuOption) {
    case enTransactionMenuOptions::Deposit:
        showDepositScreen();
        goBackToTransactionMenu();
        break;

    case enTransactionMenuOptions::Withdraw:
        showWithdrawScreen();
        goBackToTransactionMenu();
        break;

    case enTransactionMenuOptions::ShowTotalBalances:
        showTotalBalancesScreen();
        goBackToTransactionMenu();
        break;

    case enTransactionMenuOptions::MainMenu:
        goBackToMainMenu();
        break;
    }

}
     
void performMainMenuOptions(enMainMenuOptions mainMenuOption) {
    system("cls");
    switch (mainMenuOption) {
    case enMainMenuOptions::ShowClientList:
        printAllClientsTable(loadClientsDataFromFile());
        goBackToMainMenu();
        break;

    case enMainMenuOptions::AddNewClient:
        addClients();
        goBackToMainMenu();
        break;

    case enMainMenuOptions::DeleteClient:
        deleteClient();
        goBackToMainMenu();
        break;

    case enMainMenuOptions::UpdateClientInfo:
        updateClient();
        goBackToMainMenu();
        break;

    case enMainMenuOptions::FindClient:
        findClient();
        goBackToMainMenu();
        break;

	case enMainMenuOptions::TransactionMenu:
        startTransactionMenu();
		break;

    case enMainMenuOptions::Exit:
        showEndScreen();
        break;
    }

}

void showTransactionMenu() {
    system("cls");
    cout << "======================================================\n";
    cout << "\t\tTransaction Menu Screen\n";
    cout << "======================================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Show Total Balances.\n";
    cout << "\t[4] Main Menu.\n";
    cout << "======================================================\n";
}

void showMainMenu() {
    system("cls");
    cout << "=================================================\n";
    cout << "\t\tMain Menu Screen\n";
    cout << "=================================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transaction Menu.\n";
    cout << "\t[7] Exit.\n";
    cout << "=================================================\n";
}

int main() {
    startApplication();
    return 0;
}
