#include <iostream>
#include "Acc.h"
using namespace std;

Acc::Acc() : name("Unknown"), acnm(-1), blnc(0) {}

Acc::Acc(string s, int n, int b) : name(s), acnm(n), blnc(b) {}

void Acc::status() {
    cout << "Name: " << name << endl << "Acc No.: " << acnm << endl << "Balance: " << blnc << endl;
}

void Acc::setacc() {
    cout << "Enter name: ";
    cin >> name;
    cout << "New PIN: ";
    cin >> pin;
    acnm = count;
    count++;
    cout << "Successfull! Your Account No. : " << acnm << endl;
}

void Acc::withdraw(int k) {
    blnc -= k;
    cout << "Current Balance: " << blnc << endl;
}

void Acc::deposit(int k) {
    blnc += k;
    cout << "Current Balance: " << blnc << endl;
}

bool Acc::auth(int p) {
    return p == pin;
}

bool Acc::match(int a) {
    return acnm == a;
}
