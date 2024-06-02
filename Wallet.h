#include <iostream>
using namespace std;

class Wallet
{
private:
    int pin=1234;
    int balance = 500;

public:
    int EnterWalleteNo();
    bool authenticate(int p) const;
    void deposit(int amount);
    void withdraw(int amount);
};