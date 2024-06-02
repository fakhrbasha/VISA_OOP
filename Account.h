#include <iostream>
using namespace std;

class Account
{
protected:
    int balance = 0;

public:

    void deposit(int amount);

    void withdraw(int amount);

    int checkBalance() ;
};

class PremiumAccount : public Account
{

public:
    void deposit(int amount)  ;
};