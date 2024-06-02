#include <iostream>
#include "Account.h"
using namespace std;

void Account::deposit(int amount)
{
    if (amount > 1000)
    {
        cout << "Unsuccessful Transaction. The entered amount is ";
    }
    else
    {
        balance += amount;
        cout << "Your Money has been successfully deposited. Your new balance is: " << balance << endl;
    }
}

void Account::withdraw(int amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        cout << "Please collect your money and collect the card. Your new balance is: " << balance << endl;
    }
    else
    {
        cout << "Insufficient Funds." << endl;
    }
}

int Account::checkBalance()
{
    return balance;
}

void PremiumAccount::deposit(int amount)
{

    balance += amount;
    cout << "Your Money has been successfully deposited. Your new balance is: " << balance << endl;
}
