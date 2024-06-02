#include <iostream>
#include "Account.h"
#include "Wallet.h"
#include "User.h"
using namespace std;
class Node{
    public:
	int data{};
    string type;
    string transaction;
    string status;
    Node* link{};
};
Node *first = NULL, *last=NULL, *newnode;

void insert_back(int amount,string type,string transaction,string status="regular"){
	newnode=new Node;
	newnode->data = amount; 
	newnode->type = type; 
	newnode->transaction = transaction; 
	newnode->status = status; 
	newnode->link=NULL;
	
	if(first==NULL)
		first=newnode;
	else
		last->link=newnode;
	last=newnode;
}

void display(){
	Node* current = first;
	if(current==NULL)
    	cout<<"empty list"<<endl;
    else{
    	cout<<"data in the list : "<<endl;
	    while(current!=NULL){
            if (current->transaction=="deposit"){
	    	    cout<<"The deposited amount: "<<(current->data)<<endl;
            }
            else{
	    	    cout<<"The withdrawn amount: "<<(current->data)<<endl;
            }
            cout<<"The account type: "<<(current->type)<<endl;
            cout<<"The account status: "<<(current->status)<<endl;
	    	current=current->link;
    	}
	}
	cout<<endl;
}

int main()
{
    User user;
    Account account;
    PremiumAccount preAccount;
    string username;
    int password;
    char choice_user;
    int amount;
    Wallet wallet;
    int choice;
    int PIN;


    while(true){    
        cout << "1.Wallet\t2.Bank Account\n";
        cin >> choice;
        if (choice == 1)
        {
            do{
                int walletNumber= wallet.EnterWalleteNo();
                cout << "\nPlease Enter Your PIN No : " << endl;
                cin>>PIN;
                bool pin=wallet.authenticate(PIN);
                if(walletNumber && pin){
                    while(true){
                        cout << "\n1. Deposit\n2. Withdraw\n3. History\n4. Exit" << endl;
                        cout << "Choose operation: ";
                        cin >> choice;
                        switch (choice)
                        {
                            case 1:
                                cout << "\nPlease Enter The Amount Of Cash : " << endl;
                                cin >> amount;
                                wallet.deposit(amount);
                                insert_back(amount,"wallet","deposit");
                                break;
                            case 2:
                                cout << "\nPlease Enter The Amount Of Cash : " << endl;
                                cin >> amount;
                                wallet.withdraw(amount);
                                insert_back(amount,"wallet","withdraw");
                                break;
                            case 3:
                                display();
                                return 0;
                            case 4:
                                cout << "Exiting..." << endl;
                                return 0;
                            default:
                                cout << "Invalid choice." << endl;
                        }
                    }
                }
                else if(walletNumber && !pin){
                    cout<<"Invalid PIN number\nTry again? (y/n)  ";
                    cin >> choice_user;
                    if (choice_user == 'n' || choice_user == 'N')
                    {
                        cout << "Access denied.\nHave a good one.";
                        return 0;
                    }
                }
                else if(!walletNumber && pin){
                    cout<<"Invalid phone number\nTry again? (y/n)  ";
                    cin >> choice_user;
                    if (choice_user == 'n' || choice_user == 'N')
                    {
                        cout << "Access denied.\nHave a good one.";
                        return 0;
                    }
                }
                else{
                    cout<<"Invalid Input\nTry again? (y/n)  ";
                    cin >> choice_user;
                    if (choice_user == 'n' || choice_user == 'N')
                    {
                        cout << "Access denied.\nHave a good one.";
                        return 0;
                    }
                }
            }while (true);
        }
        else if (choice == 2)
        {
            do{
                cout << "Enter your username: ";
                cin >> username;
                cout << "Enter your password: ";
                cin >> password;
                cout<<"Premium Account? (y/n): ";
                cin>> choice_user;
                if (user.authenticate(username, password))
                {
                    if(choice_user=='y'||choice_user=='Y'){
                        while (true)
                        {
                            cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. History\n5. Exit" << endl;
                            cout << "Choose operation: ";
                            cin >> choice;
                            switch (choice)
                            {
                                case 1:
                                    cout << "Enter amount to deposit: ";
                                    cin >> amount;
                                    preAccount.deposit(amount);
                                    insert_back(amount,"bank account","deposit","premium");
                                    cout<< endl;
                                    break;
                                case 2:
                                    cout << "Enter amount to withdraw: ";
                                    cin >> amount;
                                    preAccount.withdraw(amount);
                                    insert_back(amount,"bank account","withdraw","premium");
                                    cout<< endl;
                                    break;
                                case 3:
                                    cout << "Your current balance is: " << preAccount.checkBalance();
                                    break;
                                case 4:
                                    display();
                                    return 0;
                                case 5:
                                    cout << "Exiting..." << endl;
                                    return 0;
                                default:
                                    cout << "Invalid choice." << endl;
                            }
                        }
                    }
                    else{
                        while (true)
                        {
                            cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. History\n5. Exit" << endl;
                            cout << "Choose operation: ";
                            cin >> choice;
                            switch (choice) {
                                case 1:
                                    cout << "Enter amount to deposit: ";
                                    cin >> amount;
                                    account.deposit(amount);
                                    insert_back(amount, "bank account", "deposit", "regular");
                                    cout << endl;
                                    break;
                                case 2:
                                    cout << "Enter amount to withdraw: ";
                                    cin >> amount;
                                    account.withdraw(amount);
                                    insert_back(amount, "bank account", "withdraw", "regular");
                                    cout << endl;
                                    break;
                                case 3:
                                    cout << "Your current balance is: " << account.checkBalance();
                                    break;
                                case 4:
                                    display();
                                    return 0;
                                case 5:
                                    cout << "Exiting..." << endl;
                                    return 0;
                                default:
                                    cout << "Invalid choice." << endl;


                            }
                        }
                    }
                }
                else
                {
                    cout << "Invalid Input.\nTry again? (y/n)  ";
                    cin >> choice_user;
                    if (choice_user == 'n' || choice_user == 'N')
                    {
                        cout << "Access denied.\nHave a good one.";
                        return 0;
                    }
                }
            }while(true);
        }
        else
        {
            cout << "Invalid Input.\n";
        }
    }


}