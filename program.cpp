#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Account {
    string name;
    double balance = 0;
    string password;
};

map<int, Account> accounts;  
int nextAccountNumber = 1000; 

void createAccount() {
    Account newAccount;
    int accountNumber = nextAccountNumber++;
    
    cout << "\nEnter your name: ";
    getline(cin, newAccount.name);
    
    cout << "Set your password: ";
    getline(cin, newAccount.password);
    
    accounts[accountNumber] = newAccount;
    
    cout << "\nAccount created successfully!\n";
    cout << "Your account number: " << accountNumber << "\n";
}

void deposit() {
    int accountNumber;
    string password;
    double amount;
    
    cout << "\nEnter your account number: ";
    cin >> accountNumber;
    cin.ignore();
    
    if (accounts.find(accountNumber) == accounts.end()) {
        cout << "Account not found!\n";
        return;
    }
    
    cout << "Enter your password: ";
    getline(cin, password);
    
    if (accounts[accountNumber].password != password){
        cout << "Incorrect password!\n";
        return;
    }
    
    cout << "Enter amount to deposit: $";
    cin >> amount;
    
    if (amount <= 0) {
        cout << "Amount must be positive.\n";
        return;
    }
    
    accounts[accountNumber].balance += amount;
    cout << "Deposit successful. New balance: $" << accounts[accountNumber].balance << "\n";
}

void withdraw() {
    int accountNumber;
    string password;
    double amount;
    
    cout << "\nEnter your account number: ";
    cin >> accountNumber;
    cin.ignore();
    
    if (accounts.find(accountNumber) == accounts.end()) {
        cout << "Account not found!\n";
        return;
    }
    
    cout << "Enter your password: ";
    getline(cin, password);
    
    if (accounts[accountNumber].password != password) {
        cout << "Incorrect password!\n";
        return;
    }
    
    cout << "Enter amount to withdraw: $";
    cin >> amount;
    
    if (amount <= 0) {
        cout << "Amount must be positive.\n";
        return;
    }
    
    if (amount > accounts[accountNumber].balance) {
        cout << "Insufficient funds!\n";
        return;
    }
    
    accounts[accountNumber].balance -= amount;
    cout << "Withdrawal successful. New balance: $" << accounts[accountNumber].balance << "\n";
}

void transferMoney() {
    int fromAccount, toAccount;
    string password;
    double amount;
    
    cout << "\nEnter your account number: ";
    cin >> fromAccount;
    cin.ignore();
    
    if (accounts.find(fromAccount) == accounts.end()) {
        cout << "Your account not found!\n";
        return;
    }
    
    cout << "Enter your password: ";
    getline(cin, password);
    
    if (accounts[fromAccount].password != password) {
        cout << "Incorrect password!\n";
        return;
    }
    
    cout << "Enter recipient account number: ";
    cin >> toAccount;
    cin.ignore();
    
    if (accounts.find(toAccount) == accounts.end()) {
        cout << "Recipient account not found!\n";
        return;
    }
    
    cout << "Enter amount to transfer: $";
    cin >> amount;
    
    if (amount <= 0) {
        cout << "Amount must be positive.\n";
        return;
    }
    
    if (amount > accounts[fromAccount].balance) {
        cout << "Insufficient funds!\n";
        return;
    }
    
    accounts[fromAccount].balance -= amount;
    accounts[toAccount].balance += amount;
    
    cout << "Transfer successful!\n";
    cout << "Your new balance: $" << accounts[fromAccount].balance << "\n";
}
void checkBalance() {
    int accountNumber;
    string password;
    
    cout << "\nEnter your account number: ";
    cin >> accountNumber;
    cin.ignore();
    
    if (accounts.find(accountNumber) == accounts.end()) {
        cout << "Account not found!\n";
        return;
    }
    
    cout << "Enter your password: ";
    getline(cin, password);
    
    if (accounts[accountNumber].password != password) {
        cout << "Incorrect password!\n";
        return;
    }
    
    cout << "Your balance: $" << accounts[accountNumber].balance << "\n";
}
void showMenu() {
    cout << "\n=== Online Banking System ===\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Transfer Money\n";
    cout << "5. Check Balance\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    
    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                transferMoney();
                break;
            case 5:
                checkBalance();
                break;
            case 6:
                cout << "Thank you for using our banking system!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
