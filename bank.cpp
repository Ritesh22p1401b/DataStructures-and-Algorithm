#include<iostream>
#include<string>
using namespace std;


class Bank {

    private:
    static double interestRate;
    string accountHolder;
    int accountNumber;
    double balance;

    public:
    Bank(string name, int accNo, double initialBalance) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest applied: " << interest << endl;
    }


    void display() {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
        cout << "interest: " << applyInterest << endl;

    }

};

int main() {
    
    Bank acc("Ritesh Pandey", 1001, 5000.00);
    acc.applyInterest();
    acc.display();
    return 0;
}

