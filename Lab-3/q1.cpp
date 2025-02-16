#include <iostream>
#include <string>
using namespace std;

class Wallet {
    string ownerName;
    double totalBalance;
    string transactionHistory;

    public:
    Wallet() {
        ownerName = "Unknown";
        totalBalance = 0.0;
        transactionHistory = "";
    }


    void addMoney(double amount) {
        
        totalBalance = totalBalance + amount;
        transactionHistory += "Added " + to_string(amount) + "\n";

    }

    void spendMoney(double amount) {
        if (amount < totalBalance && amount > 0.0) {
        totalBalance = totalBalance - amount;
        transactionHistory += "Deducted " + to_string(amount) + "\n";

        }
    }

    void displayWallet() {
        cout << "Transaction history is" << endl;
        cout << transactionHistory;
        cout << "Remaining balance in the account is " << totalBalance << endl;
    }


};

int main () {
    Wallet Saad;
    Wallet();
    Saad.addMoney(100);
    Saad.spendMoney(50);
    Saad.displayWallet();


}

