#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    private:
        string ownerName;
        long accountNumber;
        double balance;
    public:
        //Writing a Constructor using an initialization list
        BankAccount(string name, long accNum, double initialBalance)
            : ownerName(name), accountNumber(accNum), balance(initialBalance) {
            if (balance < 0) {
                balance = 0; //Ensuring balance is not negative initially
            }
        }
        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposit successful. New balance: " << balance << endl;
            } 
            else {
                cout << "Invalid deposit amount." << endl;
            }
        }
        void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdrawal successful. New balance: " << balance << endl;
            } 
            else{
                cout << "Invalid withdrawal amount or insufficient funds." << endl;
            }
        }

        void display() {
            cout << "--- Account Details ---" << endl;
            cout << "Account Holder: " << ownerName << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Current Balance: " << balance << endl;
        }
};

int main() {
    BankAccount myAccount("Srivarshan", 677000909, 10000.0);
    myAccount.display();
    myAccount.deposit(1500.0);
    myAccount.withdraw(2000.0);
    myAccount.withdraw(5000.0); //This will fail

    //Here successfully we have restricted Direct access by encapsulation
    // myAccount.balance = -1000; // This would cause a compile error
    return 0;
}