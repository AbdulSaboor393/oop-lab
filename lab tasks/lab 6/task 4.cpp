#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int id;
    float amount;

public:
    BankAccount(int accId, float accAmount) : id(accId), amount(accAmount) {}

    virtual void showDetails() {
        cout << "Account ID: " << id << endl;
        cout << "Balance: $" << amount << endl;
    }

    virtual ~BankAccount() {}
};

class FixedDepositAccount : public BankAccount {
private:
    float rateOfInterest;

public:
    FixedDepositAccount(int accId, float accAmount, float interestRate) 
        : BankAccount(accId, accAmount), rateOfInterest(interestRate) {}

    void showDetails() override {
        BankAccount::showDetails();
        cout << "Interest Rate: " << rateOfInterest << "%" << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    float withdrawalLimit;

public:
    CurrentAccount(int accId, float accAmount, float limit) 
        : BankAccount(accId, accAmount), withdrawalLimit(limit) {}

    void showDetails() override {
        BankAccount::showDetails();
        cout << "Withdrawal Limit: $" << withdrawalLimit << endl;
    }
};

int main() {
    int accId;
    float accAmount, interestRate, withdrawalLimit;

    cout << "Enter Fixed Deposit Account details:\n";
    cout << "Account ID: ";
    cin >> accId;
    cout << "Balance: ";
    cin >> accAmount;
    cout << "Interest Rate in %: ";
    cin >> interestRate;
    FixedDepositAccount fixedDeposit(accId, accAmount, interestRate);

    cout << "\nEnter Current Account details:\n";
    cout << "Account ID: ";
    cin >> accId;
    cout << "Balance: ";
    cin >> accAmount;
    cout << "Withdrawal Limit: ";
    cin >> withdrawalLimit;
    CurrentAccount current(accId, accAmount, withdrawalLimit);

    cout << "\nFixed Deposit Account Details:\n";
    fixedDeposit.showDetails();

    cout << "\nCurrent Account Details:\n";
    current.showDetails();
}
