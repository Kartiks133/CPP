#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

struct Account {
    string name;
    string dob;
    string aadhaar;
    string phone;
    int account_number;
    double balance;
};

class BankOf404BrainNotFound {
private:
    string admin_id = "admin404";
    string admin_password = "password";
    vector<Account> accounts;
    Account* current_user = nullptr;

    int generateAccountNumber() {
        return 1000000000 + rand() % 900000000;
    }

public:
    BankOf404BrainNotFound() {
        srand(time(nullptr));
    }

    void adminLogin() {
        string id, password;
        cout << "Enter Admin ID: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> password;

        if (id == admin_id && password == admin_password) {
            cout << "Admin login successful!\n";
            adminPanel();
        } else {
            cout << "Invalid Admin ID or Password.\n";
        }
    }

    void adminPanel() {
        while (true) {
            cout << "\nAdmin Panel\n1. View All Accounts\n2. Add Account\n3. Remove Account\n4. Logout\nEnter choice: ";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    viewAccounts();
                    break;
                case 2:
                    if (accounts.size() >= 5) {
                        cout << "Cannot add more than 5 accounts!\n";
                    } else {
                        openAccount();
                    }
                    break;
                case 3:
                    removeAccount();
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice.\n";
            }
        }
    }

    void viewAccounts() {
        if (accounts.empty()) {
            cout << "No accounts found.\n";
            return;
        }
        for (size_t i = 0; i < accounts.size(); ++i) {
            cout << "Account " << i + 1 << " - Name: " << accounts[i].name
                 << ", Account Number: " << accounts[i].account_number
                 << ", Balance: " << accounts[i].balance << "\n";
        }
    }

    void openAccount() {
        Account new_acc;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, new_acc.name);
        cout << "Enter DOB (DD/MM/YYYY): ";
        cin >> new_acc.dob;
        cout << "Enter Aadhaar (12 digits): ";
        cin >> new_acc.aadhaar;
        cout << "Enter Phone (10 digits): ";
        cin >> new_acc.phone;

        if (new_acc.aadhaar.size() != 12 || new_acc.phone.size() != 10) {
            cout << "Invalid Aadhaar or Phone number.\n";
            return;
        }

        new_acc.account_number = generateAccountNumber();
        new_acc.balance = 500;

        accounts.push_back(new_acc);
        cout << "Account created successfully! Account Number: " << new_acc.account_number << "\n";
    }

    void removeAccount() {
        int acc_num;
        cout << "Enter Account Number to remove: ";
        cin >> acc_num;
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->account_number == acc_num) {
                accounts.erase(it);
                cout << "Account removed successfully.\n";
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void userLogin() {
        if (accounts.empty()) {
            cout << "No accounts available! Admin must create accounts first.\n";
            return;
        }

        int acc_num;
        cout << "Enter Account Number: ";
        cin >> acc_num;
        for (auto &acc : accounts) {
            if (acc.account_number == acc_num) {
                current_user = &acc;
                cout << "User login successful!\n";
                userPanel();
                return;
            }
        }
        cout << "Account not found!\n";
    }

    void userPanel() {
        while (true) {
            cout << "\nUser Panel\n1. Deposit Money\n2. Withdraw Money\n3. View Account\n4. Logout\nEnter choice: ";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    depositMoney();
                    break;
                case 2:
                    withdrawMoney();
                    break;
                case 3:
                    viewAccount();
                    break;
                case 4:
                    current_user = nullptr;
                    return;
                default:
                    cout << "Invalid choice.\n";
            }
        }
    }

    void depositMoney() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount > 0) {
            current_user->balance += amount;
            cout << "Deposited " << amount << " successfully.\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdrawMoney() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > 0) {
            if (current_user->balance - amount < 500) {
                cout << "Insufficient balance! Minimum balance of 500 required.\n";
            } else {
                current_user->balance -= amount;
                cout << "Withdrawn " << amount << " successfully.\n";
            }
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void viewAccount() {
        cout << "\nAccount Details\nName: " << current_user->name
             << "\nAccount Number: " << current_user->account_number
             << "\nBalance: " << current_user->balance << "\n";
    }

    void run() {
        while (true) {
            cout << "\nSimple Bank\n1. Admin Login\n2. User Login\n3. Exit\nEnter choice: ";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    adminLogin();
                    break;
                case 2:
                    userLogin();
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid choice.\n";
            }
        }
    }
};

int main() {
    BankOf404BrainNotFound bank;
    bank.run();
    return 0;
}
