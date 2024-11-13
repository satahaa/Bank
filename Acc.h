#ifndef ACC_H
#define ACC_H

#include <string>

using namespace std;

class Acc {
public:
    Acc();
    Acc(string s, int n, int b);

    void status();
    void setacc();
    void withdraw(int k);
    void deposit(int k);
    bool auth(int p);
    bool match(int a);

private:
    string name;
    static int count;
    int acnm;
    int blnc;
    int pin;
};

#endif // ACC_H
