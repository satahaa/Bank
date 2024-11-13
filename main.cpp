#include <iostream>
#include "Acc.h"
#include <vector>
using namespace std;
void repeat();
int Acc::count = 0;
vector<Acc> accounts;
int main()
{
    cout << "\t\tWelcome to Runtime Banking!!\n\n";

    repeat();

    cout << "Exited!\n";
    return 0;
}


void repeat()
{
    while (true) {
        cout << "What would you like to do?: \n1: Open Account\n2: Status\n3: Withdraw\n4: Deposit\n5: Exit\n=> ";
        int f;
        cin >> f;

        if (f == 5) break;

        if (f < 1 || f > 5) {
            cout << "Wrong command\n";
            continue;
        }

        switch (f) {
            case 1: {
                Acc a;
                a.setacc();
                accounts.push_back(a);
                break;
            }
            case 2: {
                int accNum, pin;
                cout << "Enter Account No.: ";
                cin >> accNum;
                cout << "Enter PIN: ";
                cin >> pin;
                bool found = false;
                for (auto& acc : accounts) {
                    if (acc.match(accNum)) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                else if (!accounts[accNum].auth(pin)) {
                    cout << "Wrong PIN\n";
                }
                else {
                    accounts[accNum].status();
                }
                break;
            }
            case 3: {
                int accNum, amount, pin;
                cout << "Enter Account No.: ";
                cin >> accNum;
                cout << "Enter PIN: ";
                cin >> pin;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bool found = false;
                for (auto& acc : accounts) {
                    if (acc.match(accNum)) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                else if (!accounts[accNum].auth(pin)) {
                    cout << "Wrong PIN\n";
                }
                else {
                    accounts[accNum].withdraw(amount);
                }
                break;
            }
            case 4: {
                int accNum, amount, pin;
                cout << "Enter Account No.: ";
                cin >> accNum;
                cout << "Enter PIN: ";
                cin >> pin;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bool found = false;
                for (auto& acc : accounts) {
                    if (acc.match(accNum)) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found.\n";
                }
                else if (!accounts[accNum].auth(pin)) {
                    cout << "Wrong PIN\n";
                }
                else {
                    accounts[accNum].deposit(amount);
                }
                break;
            }
            default: {
                cout << "Something went wrong!\n";
            }
        }
    }
}