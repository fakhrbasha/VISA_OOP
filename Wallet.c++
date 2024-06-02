#include <iostream>
#include "Wallet.h"
#include <string.h>

using namespace std;

int Wallet::EnterWalleteNo()
{
    string phone;
    cout << "\nPlease Enter Your Wallet Number : " << endl;
    cin>>phone;
   int size= phone.size();

   if(size==11&&phone[0]=='0'&&phone[1]=='1'){
       return 1;
   }
   else{
       return 0;
   }


}
bool Wallet:: authenticate( int p) const
    {

        if (pin==p)
        {
            cout << endl
                 << "Access granted!!" << endl;
            return true;
        }
        return false;
    }



void Wallet::deposit(int amount)
{

    if (amount > 8000)
    {
        cout << "Unsuccessful Transaction. Maximum valid deposition surpassed.";
    }
    else
    {
        balance += amount;
        cout << "Your Money has been successfully deposited. "<< endl;
    }
}
void Wallet::withdraw(int amount)
{

    if (balance >= amount)
    {
        balance -= amount;
        cout << "Please collect your money ."<< endl;
    }
    else
    {
        cout << "Insufficient Funds." << endl;
    }
}
