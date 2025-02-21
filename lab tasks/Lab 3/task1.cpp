#include <iostream>
#include <string>
using namespace std;

class Wallet{
    private:
        string userName;
        double currentBalance;
        double startingBalance;
        string transactionLog[100];
        int transactionCount;
    public:
        Wallet(string name, double initBalance){
            userName = name;
            currentBalance = initBalance;
            startingBalance = initBalance;
            transactionCount = 0;
        }

        void deposit(double amount){
            if (amount > 0){
                currentBalance += amount;
                transactionLog[transactionCount] = "Deposited: " + to_string(amount);
                transactionCount++;
                cout << "Amount Deposited" << endl;
            } else {
                cout << "Invalid amount. Please enter a positive value." << endl;
            }
        }

        void withdraw(double amount){
            if(amount > currentBalance){
                cout << "Insufficient funds." << endl;
            } else if(amount < 0){
                cout << "Error. Please enter a positive amount." << endl;
            } else {
                currentBalance -= amount;
                transactionLog[transactionCount] = "Withdrawn: " + to_string(amount);
                transactionCount++;
                cout << "Withdrawal Successful. Remaining Balance: " << currentBalance << endl;
            }
        }

        void showTransactionHistory(){
            cout << "Transaction History: " << endl << endl;
            if(transactionCount == 0){
                cout << "No transactions yet." << endl;
            } else {
                for(int i = 0; i < transactionCount; i++){
                    cout << transactionLog[i] << endl;
                }
            }
        }

        void checkLowBalance(){
            if(currentBalance <= startingBalance / 2){
                cout << "Warning: Low Balance" << endl;
            } else {
                cout << "Balance is sufficient" << endl;
            }
        }

        void showBalance(){
            cout << "Current Balance: " << currentBalance << endl;
        }
};

int main(){
    Wallet userWallet("Saad", 50000);
    userWallet.deposit(10000);
    userWallet.showBalance();
    userWallet.withdraw(20000);
    userWallet.withdraw(10000);
    userWallet.showBalance();
    userWallet.checkLowBalance();
    userWallet.showTransactionHistory();
}

