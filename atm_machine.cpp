#include <iostream>
#include <iomanip>   // for formatting
#include <string>
#include <limits>    // for input validation
#include <unistd.h>  // for sleep function (optional delay)
#include <vector>    // for storing transaction history

using namespace std;

class ATM {
private:
    string username;
    int pin;
    double balance;
    vector<string> transactionHistory;  // To store the user's transaction history
    int failedLoginAttempts = 0;        // Counter for failed login attempts

public:
    ATM(string user, int p, double bal) : username(user), pin(p), balance(bal) {}

    bool login(int inputPin) {
        if (failedLoginAttempts >= 3) {
            cout << "Your account has been locked due to multiple failed attempts.\n";
            return false;
        }
        if (pin == inputPin) {
            failedLoginAttempts = 0;
            return true;
        } else {
            failedLoginAttempts++;
            return false;
        }
    }

    void displayHeader() {
        cout << "============================================\n";
        cout << "=              WELCOME TO ATM              =\n";
        cout << "============================================\n\n";
    }

    void displayFooter() {
        cout << "\n============================================\n";
        cout << "=       THANK YOU FOR USING OUR ATM        =\n";
        cout << "============================================\n";
    }

    void displayMainMenu() {
        cout << "********************************************\n";
        cout << "*                 MAIN MENU                *\n";
        cout << "********************************************\n";
        cout << "*  1. Check Balance                        *\n";
        cout << "*  2. Deposit Money                        *\n";
        cout << "*  3. Withdraw Money                       *\n";
        cout << "*  4. View Transaction History             *\n";
        cout << "*  5. Change PIN                           *\n";
        cout << "*  6. Exit                                 *\n";
        cout << "********************************************\n";
        cout << "Please choose an option: ";
    }

    void checkBalance() {
        cout << "\n============================================\n";
        cout << "=              CURRENT BALANCE             =\n";
        cout << "============================================\n";
        cout << "=        Your balance: $ " << fixed << setprecision(2) << balance << "        =\n";
        cout << "============================================\n\n";
        sleep(2);
    }

    void depositMoney() {
        double amount;
        cout << "\n============================================\n";
        cout << "=               DEPOSIT MONEY              =\n";
        cout << "============================================\n";
        cout << "Enter the amount to deposit: $";
        cin >> amount;

        // Input validation
        while (cin.fail() || amount <= 0) {
            cout << "Invalid input! Please enter a valid amount: $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> amount;
        }

        balance += amount;
        transactionHistory.push_back("Deposited: $" + to_string(amount));
        cout << "\nDeposit successful! Your new balance is $" << fixed << setprecision(2) << balance << "\n";
        cout << "============================================\n\n";
        sleep(2);
    }

    void withdrawMoney() {
        double amount;
        cout << "\n============================================\n";
        cout << "=              WITHDRAW MONEY              =\n";
        cout << "============================================\n";
        cout << "Enter the amount to withdraw: $";
        cin >> amount;

        // Input validation
        while (cin.fail() || amount <= 0) {
            cout << "Invalid input! Please enter a valid amount: $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> amount;
        }

        if (amount > balance) {
            cout << "\nInsufficient balance! You have only $" << fixed << setprecision(2) << balance << " available.\n";
        } else {
            balance -= amount;
            transactionHistory.push_back("Withdrew: $" + to_string(amount));
            cout << "\nWithdrawal successful! Your new balance is $" << fixed << setprecision(2) << balance << "\n";
        }
        cout << "============================================\n\n";
        sleep(2);
    }

    void viewTransactionHistory() {
        cout << "\n============================================\n";
        cout << "=           TRANSACTION HISTORY            =\n";
        cout << "============================================\n";
        if (transactionHistory.empty()) {
            cout << "No transactions available.\n";
        } else {
            for (const auto& transaction : transactionHistory) {
                cout << "=  " << transaction << "\n";
            }
        }
        cout << "============================================\n\n";
        sleep(2);
    }

    void changePIN() {
        int oldPin, newPin;
        cout << "\n============================================\n";
        cout << "=               CHANGE PIN                 =\n";
        cout << "============================================\n";
        cout << "Enter your current PIN: ";
        cin >> oldPin;

        if (oldPin == pin) {
            cout << "Enter your new PIN: ";
            cin >> newPin;
            pin = newPin;
            cout << "\nPIN changed successfully!\n";
        } else {
            cout << "\nIncorrect PIN. Unable to change.\n";
        }
        cout << "============================================\n\n";
        sleep(2);
    }
};

int main() {
    string user = "John Doe";
    int pin = 1234;
    double initialBalance = 5000.00;
    ATM atm(user, pin, initialBalance);

    int inputPin, choice;
    bool authenticated = false;

    atm.displayHeader();

    // PIN Authentication
    cout << "Enter your PIN: ";
    cin >> inputPin;

    if (atm.login(inputPin)) {
        authenticated = true;
        cout << "\nLogin successful! Welcome, " << user << ".\n";
    } else {
        cout << "\nInvalid PIN. Exiting...\n";
        return 0;
    }

    // Main Menu
    while (authenticated) {
        atm.displayMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                atm.checkBalance();
                break;
            case 2:
                atm.depositMoney();
                break;
            case 3:
                atm.withdrawMoney();
                break;
            case 4:
                atm.viewTransactionHistory();
                break;
            case 5:
                atm.changePIN();
                break;
            case 6:
                atm.displayFooter();
                authenticated = false;
                break;
            default:
                cout << "Invalid option! Please select a valid option.\n";
        }
    }

    return 0;
}
