#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string account_number;
    string owner_name;
    double balance;

public:
    BankAccount(string account_number, string owner_name, double initial_balance)
        : account_number(account_number), owner_name(owner_name), balance(initial_balance) {}


    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        }
        else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }


    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        }
        else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    void display_account_info() const {
        cout << "Account Number: " << account_number << endl;
        cout << "Owner Name: " << owner_name << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interest_rate;  

public:
    SavingsAccount(string account_number, string owner_name, double initial_balance, double interest_rate)
        : BankAccount(account_number, owner_name, initial_balance), interest_rate(interest_rate) {}

    void apply_interest() {
        double interest =  (interest_rate / 100);
        deposit(interest);  
        cout << "Interest applied at " << interest_rate << "%. New balance: " <<   endl;
    }
};

int main() {
  
    BankAccount account1("12345", "Lina", 1000.0);
    account1.display_account_info();
    account1.deposit(500);
    account1.withdraw(200);

    cout << endl;


    SavingsAccount savings_account("67890", "Alexandr", 2000.0, 5.0); // Interest rate 5%
    savings_account.display_account_info();
    savings_account.deposit(1000);
    savings_account.withdraw(500);
    savings_account.apply_interest();  

    return 0;
}
